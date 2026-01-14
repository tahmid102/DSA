#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define Pair pair<ll,int>
#define inf 1e18

int main(){
    int n,m,k;
    cin>>n>>m>>k;
    vector<vector<Pair>>adj(n);
    priority_queue<Pair, vector<Pair>,greater<Pair>>pq;
    for(int i=0;i<m;i++){
        int a,b;
        ll c;
        cin>>a>>b>>c;
        adj[a-1].push_back({c,b-1});
    }
    
    pq.push({0,0});
    vector<int>count(n,0);
    vector<ll>result;
    while(!pq.empty()&& count[n-1]<k){
        int u=pq.top().second;
        ll d=pq.top().first;
        pq.pop();
        if(count[u] >= k) continue;
        count[u]++;
        if(u==n-1)result.push_back(d);
        
        for(auto it:adj[u]){
            int v=it.second;
            ll weight=it.first;
            
            
                pq.push({d+weight,v});
            
        }
    }
    for(int i=0;i<k;i++){
        cout<<result[i]<<" ";
    }
}