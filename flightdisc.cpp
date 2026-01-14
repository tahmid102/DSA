
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define Pair pair<ll,int>
#define inf 1e18
vector<ll> dijkstra(int s,int n,vector<vector<Pair>>&adj){
    priority_queue<Pair, vector<Pair>,greater<Pair>>pq;
    vector<ll> dist(n,inf);
    dist[s-1]=0;
    pq.push({0,s-1});
    while(!pq.empty()){
        int u=pq.top().second;
        ll d=pq.top().first;
        pq.pop();
        if(d>dist[u])continue;
        for(auto it:adj[u]){
            int v=it.second;
            ll weight=it.first;
            if(dist[v]>dist[u]+weight){
                dist[v]=dist[u]+weight;
                pq.push({dist[v],v});
            }
        }
    }
    return dist;
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<Pair>>from_s(n);
    vector<vector<Pair>>from_d(n);
    
    for(int i=0;i<m;i++){
        int a,b;
        ll c;
        cin>>a>>b>>c;
        from_s[a-1].push_back({c,b-1});
        from_d[b-1].push_back({c,a-1});
    }
    vector<ll>sToD=dijkstra(1,n,from_s);
    vector<ll>dToS=dijkstra(n,n,from_d);
    ll result=inf;
    for(int i=0;i<n;i++){
        for(auto it:from_s[i]){
            ll weight=it.first;
            int v=it.second;
            result=min(result,(sToD[i]+dToS[v]+weight/2));
        }
    }
    cout<<result<<endl;
}