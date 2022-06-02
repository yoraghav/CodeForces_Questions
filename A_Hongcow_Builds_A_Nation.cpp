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

int find_parent(int i,vi &parent){
    if(parent[i]==i){return i;}
    return parent[i] = find_parent(parent[i],parent);
}
void set_union(int a,int b,vi &parent,vi &sz,vi &gov){
    int q = find_parent(a,parent);
    int w = find_parent(b,parent);
    if(q!=w){
        if(gov[w]>0){
            swap(q,w);
        }
        sz[q] += sz[w];
        parent[w] = q;
    }
}


void solve(){
    int n,m,k;cin>>n>>m>>k;
    vi gov(n+1,0),parent(n+1),sz(n+1,1);
    repr(n+1){
        parent[i] = i;
    }
    vi govs(k);
    repr(k){
        cin>>govs[i];
        gov[govs[i]]++;
    }
    repr(m){
        int a,b;
        cin>>a>>b;
        set_union(a,b,parent,sz,gov);
    }
    int maxgov=1;
    int maxm=0;
    repr(k){
        if(maxm<sz[govs[i]]){
            maxm = sz[govs[i]];
            maxgov = govs[i];
        }
    }
    int calc=0;
    repr(n){
        if(gov[find_parent(i+1,parent)]==0){
            calc++;
        }
    }
    sz[maxgov]+=calc;
    int ans=0;
    repr(k){
        int bb = sz[govs[i]];
        ans += (bb*(bb-1))/2;
    }
    cout<<(ans-m)<<endl;
    // prin(parent);

}

signed main(){
    // ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t=1,curr=1;
    // cin>>t;
    while (t--){
        //cout<<"Case #"<<curr++<<": ";
        solve();
    }
    return 0;
}
