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

int lim = 500+1;
vvi edges;
int find_parent(int i,vi &parent){
    if(parent[i]==i){return i;}
    return parent[i] = find_parent(parent[i],parent);
}
void set_union(int a,int b,vi &parent,vi & sz){
    int q = find_parent(a,parent);
    int w = find_parent(b,parent);
    if(q!=w){
        if(sz[q]<sz[w]){
            swap(q,w);
        }
        sz[q] += sz[w];
        parent[w] = q;
    }
}
vi gold;
int G,S;

int forgold(int g,int n,int m){
    vvi edches;
    repr(m){
        if(gold[i]<=g){
            edches.pb(edges[i]);
        }
    }
    sort(all(edches));
    int size = edches.size();
    vi parent(n+1),sz(n+1,1);
    repr(n+1){
        parent[i]=i;
    }
    int s=0;
    for(auto i : edches){
        int a = find_parent(i[1],parent);
        int b = find_parent(i[2],parent);
        if(a!=b){
            set_union(a,b,parent,sz);
            if(i[0]>s){
                s=i[0];
            }
        }
    }
    int node = find_parent(1,parent);
    repr(n){
        if(find_parent(i+1,parent)!=node){
            return INT64_MAX;
        }
    }
    return (g*G+S*s);
}


void solve(){
    int n,m;cin>>n>>m;
    cin>>G>>S;
    int l = m;
    repr(l){
        int x,y,g1,s1;
        cin>>x>>y>>g1>>s1;
        if(x==y){
            m--;
        }
        else{
            edges.pb({s1,x,y});
            gold.pb(g1);
        }
    }
    int mid;
    int ans=INT64_MAX;
    repr(m){
        int a = forgold(gold[i],n,m);
        if(a>0){
            ans = min(ans,a);
        }
    }
    if(ans == INT64_MAX){
        cout<<-1<<endl;return;
    }
    cout<<ans<<endl;
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
