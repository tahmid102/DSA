#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define Pair pair<ll,int>
#define inf 1e18
int main(){
    int n,m,k,b,e;
    cin>>n>>m>>k>>b>>e;
    vector<int> captitals;
    for(int i=0;i<k;i++){
        int c;
        cin>>c;
        captitals.push_back(c-1);
    }
    vector<bool> blocked(n,false);
    for(int i=0;i<b;i++){
        int bl;
        cin>>bl;
        blocked[bl-1]=true;
    }
    vector<int> emergency;
    for(int i=0;i<e;i++){
        int em;
        cin>>em;
        emergency.push_back(em-1);
    }

    
    vector<vector<Pair>>adj(n);
    for(int i=0;i<m;i++){
        
        int a,m;
        ll c;
        cin>>a>>m>>c;
        if(blocked[m-1]||blocked[a-1])continue;
        
        adj[a-1].push_back({c,m-1});
    }
    vector<ll> dist(n,inf);
    
    
    for(int i=0;i<k;i++){
        dist[captitals[i]]=0;
    }
    bool iscycle;
    for(int i=0;i<n;i++){
        iscycle=false;
        
        for(int u=0;u<n;u++){
            if(dist[u]==inf)continue;
            for(auto it:adj[u]){
                int v=it.second;
                ll w=it.first;
                if(dist[v]>dist[u]+w){
                    dist[v]=dist[u]+w;
                    
                    iscycle=true;
                    
                }
            }
        }
    }
    if(iscycle){
        
        cout<<"Abyss Detected"<<endl;
    }
    else {
        for(int i=0;i<e;i++){
            cout<<dist[emergency[i]]<<endl;
        }
    }
}