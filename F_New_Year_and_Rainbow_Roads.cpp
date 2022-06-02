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

void solve(){
    int n;cin>>n;
    int R=-1,B=-1;
    vector<pair<int,char>> tot(n);
    int g1=0,g2=0;
    for(int i=0;i<n;i++){
        cin>>tot[i].ff>>tot[i].ss;
        if(g1==0 && tot[i].ss=='G'){
            g1=tot[i].ff;
        }
        if(tot[i].ss=='G'){
            g2=tot[i].ff;
        }
    }
    int cost = g2 - g1;
    for(int i=0;i<n;i++){
        if(tot[i].ss == 'G' && R!=-1){
            int rend=i;
            int maxedge = 0;
            int total = tot[rend].ff - tot[R].ff;
            int mid=-1;
            rep(r,R+1,rend+1){
                if(tot[r].ss=='R'||tot[r].ss=='G'){
                    if(mid==-1){
                        mid = r;
                    }
                    else{
                        maxedge = max(maxedge,(max(tot[r].ff - tot[mid].ff,tot[mid].ff-tot[R].ff)));
                        R = mid;
                        mid = r;
                    }
                }
            }
            if(maxedge){
                cost += total-maxedge;
            }
            R = rend;
        }
        else if(tot[i].ss == 'G'){
            rep(j,0,i){
                if(tot[j].ss=='R'){
                    cost += tot[i].ff - tot[j].ff;
                    break;
                }
            }
            R = i;
        }
    }
    
    for(int i=n-1;i>R;i--){
        if(tot[i].ss=='R'){
            cost+=tot[i].ff-tot[R].ff;
            break;
        }
    }
    
    for(int i=0;i<n;i++){
        if(tot[i].ss == 'G' && B!=-1){
            int rend=i;
            int maxedge = 0;
            int total = tot[rend].ff - tot[B].ff;
            int mid=-1;
            rep(r,B+1,rend+1){
                if(tot[r].ss=='B'||tot[r].ss=='G'){
                    if(mid==-1){
                        mid = r;
                    }
                    else{
                        maxedge = max(maxedge,(max(tot[r].ff - tot[mid].ff,tot[mid].ff-tot[B].ff)));
                        B = mid;
                        mid = r;
                    }
                }
            }
            if(maxedge!=0){
                cost += total-maxedge;
            }
            B = rend;
        }
        else if(tot[i].ss == 'G'){
            rep(j,0,i){
                if(tot[j].ss=='B'){
                    cost += tot[i].ff - tot[j].ff;
                    break;
                }
            }
            B = i;
        }
    }
    for(int i=n-1;i>B;i--){
        if(tot[i].ss=='B'){
            cost+=tot[i].ff-tot[B].ff;
            break;
        }
    }
    cout<<cost<<endl;
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
