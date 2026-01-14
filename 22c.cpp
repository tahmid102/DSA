#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define Pair pair<ll,int>
#define inf 1e18

int main(){
    int n,m,f;
    cin>>n>>m>>f;
    vector<int>capacity;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        capacity.push_back(a);
    }
    vector<vector<Pair>>adj(n);
    priority_queue<Pair, vector<Pair>,greater<Pair>>pq;
    for(int i=0;i<m;i++){
        int a,b;
        ll c;
        cin>>a>>b>>c;
        adj[a-1].push_back({c,b-1});
    }
    int k;
    cin>>k;
    vector<ll> dist(n,inf);
    dist[0]=0;
    pq.push({0,0});
    vector<int>closest;
    while(!pq.empty()){
        int u=pq.top().second;
        ll d=pq.top().first;
        pq.pop();
        if(d>dist[u])continue;
        closest.push_back(u);
        for(auto it:adj[u]){
            int v=it.second;
            ll weight=it.first;
            if(dist[v]>dist[u]+weight){
                dist[v]=dist[u]+weight;
                pq.push({dist[v],v});
            }
        }
    }
    int s=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<capacity[closest[i]];j++){
            cout<<dist[closest[i]]+f<<" ";
            if(++s==k)break;
        }
        if(s==k)break;
    }

}