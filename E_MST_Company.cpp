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

vi parent(5001);

vi sz(5001,1);

int find_parent(int i){
    if(parent[i]==i){return i;}
    return parent[i] = find_parent(parent[i]);
}
void set_union(int a,int b){
    int q = find_parent(a);
    int w = find_parent(b);
    if(q!=w){
        if(sz[q]<sz[w]){
            swap(q,w);
        }
        sz[q] += sz[w];
        parent[w] = q;
    }
}
void set_union_capital(int a,int b){
    int q = find_parent(a);
    int w = find_parent(b);
    if(q!=w){
        if(w==1){
            swap(q,w);
        }
        sz[q] += sz[w];
        parent[w] = q;
    }
}

void solve(){
    repr(5001){
        parent[i]=i;
    }
    int n,m,k;cin>>n>>m>>k;
    vvi edges;
    vvi vipedges;
    map<int,int> mp;
    repr(m){
        int x,y,z;
        cin>>x>>y>>z;
        if(x==1||y==1){
            mp[x*y]++;
            vipedges.pb({z,x,y,i+1});
        }
        else
            edges.pb({z,x,y,i+1});
    }
    sort(all(edges));
    vi ans;
    for(auto i : edges){
        int a = find_parent(i[1]);
        int b = find_parent(i[2]);
        if(mp[a] && mp[b]){
            vipedges.pb(i);
        }
        else{
            set_union(a,b);
            ans.pb(i[4]);
        }
    }
    for(auto i : edges){
        int a = find_parent(i[1]);
        int b = find_parent(i[2]);
        if(mp[a] && mp[b]){
            vipedges.pb(i);
        }
        else{
            set_union(a,b);
            ans.pb(i[4]);
        }
    }
    sort(all(vipedges));
    vi ans2(vipedges.size(),0);
    int cap=0;
    for(int j=0;j<vipedges.size();j++){
        vi i = vipedges[j];
        int a = find_parent(i[1]);
        int b = find_parent(i[2]);
        if(a==1 && b==1){
            
        }
        if(a==b){
            continue;
        }
        if((i[1]==1 || i[2]==1) && cap<k){
            cap++;
            set_union_capital(a,b);
            ans2[j] = 1;
        }
        else{
            set_union(a,b);
            ans2[j] = 1;
        }
    }
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
