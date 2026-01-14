#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define Pair pair<ll,int>
#define inf 1e18
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<Pair>>adj(n);
    for(int i=0;i<m;i++){
        int a,b;
        ll c;
        cin>>a>>b>>c;
        adj[a-1].push_back({c,b-1});
    }
    vector<ll> dist(n,0);
    vector<int>parent(n,-1);
    int x;
    dist[0]=0;
    bool iscycle;
    for(int i=0;i<n;i++){
        iscycle=false;
        x=-1;
        for(int u=0;u<n;u++){
            if(dist[u]==inf)continue;
            for(auto it:adj[u]){
                int v=it.second;
                ll w=it.first;
                if(dist[v]>dist[u]+w){
                    dist[v]=dist[u]+w;
                    parent[v]=u;
                    iscycle=true;
                    x=v;
                }
            }
        }
    }
    if(iscycle){
        for (int i = 0; i < n; i++) x = parent[x];
        cout<<"YES"<<endl;
        vector<int>cycle;
        cycle.push_back(x);
        int curr=parent[x];
        while(true){
            cycle.push_back(curr);
            if(curr==x)break;
            curr=parent[curr];
        }
        reverse(cycle.begin(),cycle.end());
        for(int i=0;i<cycle.size();i++){
            cout<<cycle[i]+1<<" ";
        }
    }
    else cout<<"NO"<<endl;
}