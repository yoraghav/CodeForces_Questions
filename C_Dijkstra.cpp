#include "bits/stdc++.h"
#include <unordered_map>
 
using namespace std;
#define int long long int
#define vi vector<int>
#define pii pair<int,int>
#define vii vector<pii>
#define vvi vector<vi>
#define rep(i,a,b) for(int i=a; i<b; i++)
#define repr(b) for(int i=0; i<b; i++)
#define prin(vec) for(int i=0;i<vec.size();i++){cout<<vec[i]<<" ";}cout<<endl
#define newvec(x,n) vi x(n);rep(i,0,n){cin>>x[i];}
#define newvecn(x,n) int n;cin>>n;vi x(n);repr(n){cin>>x[i];}
#define float long double
#define vip vector<int>::iterator
#define mod 1000000007
#define all(a) a.begin(),a.end()
#define ff first 
#define ss second 
#define pb push_back
#define neg cout<<"NO"<<endl;return;
#define pos cout<<"YES"<<endl;return;
#define intin a int a;cin>>a
#define mii map<int,int>
#define miv map<int,vi>
#define miit mii::iterator
#define mivt miv::iterator
#define matrix(x,n,m,g) vector<vi> x(n,vi(m,g)) 
#define pqi priority_queue<int>
#define qi queue<int>


vi dijkstra(vector<vii> &adj,int node,int n){
    vi dist(n+1,INT64_MAX),vis(n+1,0);
    vis[node] = 1;
    dist[node] = 0;
    priority_queue<pii,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push({0,node});
    vi parent(n+1,0);
    while(!pq.empty()){
        pii a = pq.top();
        pq.pop();
        vis[a.ss]=1;
        for(auto i:adj[a.ss]){
            if(dist[i.ff] > dist[a.ss]+i.ss){
                dist[i.ff] = dist[a.ss]+i.ss;
                parent[i.ff] = a.ss;
            }
            if(vis[i.ff]==0){
                pq.push({dist[i.ff],i.ff});
            }
        }
        while(!pq.empty() && vis[pq.top().ss]){
            pq.pop();
        }
    }
    // prin(dist);
    return parent;
}

void solve(){
    int n,m;
    cin>>n>>m;
    vector<vector<pii>> edges(n+1);
    repr(m){
        int a,b,c;
        cin>>a>>b>>c;
        edges[a].pb({b,c});
        edges[b].pb({a,c});
    }
    vi x = dijkstra(edges,1,n);
    // prin(x);
    int a = n;
    stack<int> path;
    while(a!=0){
        path.push(a);
        a = x[a];
    }
    if(path.top()==1){
        while(!path.empty()){
            cout<<path.top()<<" ";
            path.pop();
        }
        cout<<endl;return;
    }
    cout<<-1<<endl;
}


signed main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t=1,curr=1;
    // cin>>t;
    while (t--){
        //cout<<"Case #"<<curr++<<": ";
        solve();
    }
    return 0;
}
