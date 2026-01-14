#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define Pair pair<ll,int>
#define inf 1e18

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<Pair>>adj(n);
    priority_queue<Pair, vector<Pair>,greater<Pair>>pq;
    for(int i=0;i<m;i++){
        int a,b;
        ll c;
        cin>>a>>b>>c;
        adj[a-1].push_back({c,b-1});
    }
    vector<int>parent(n,-1);
    vector<ll> dist(n,inf);
    dist[0]=0;
    bool found=false;
    pq.push({0,0});
    while(!pq.empty()){
        int u=pq.top().second;
        ll d=pq.top().first;
        pq.pop();
        if(u==n-1){
            found=true;
            break;
        }
        if(d>dist[u])continue;
        for(auto it:adj[u]){
            int v=it.second;
            ll weight=it.first;
            if(dist[v]>dist[u]+weight){
                dist[v]=dist[u]+weight;
                pq.push({dist[v],v});
                parent[v]=u;
            }
        }
    }
    if(found){
        stack<int> result;
        int curr=n-1;
        while(curr!=-1){
            result.push(curr);
            curr=parent[curr];
        }
        while(!result.empty()){
            cout<<result.top()+1<<" ";
            result.pop();
        }
    }
    else cout<<-1;
}