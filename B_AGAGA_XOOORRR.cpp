#include "bits/stdc++.h"
 
using namespace std;
#define int long long int
#define vi vector<int>
#define pii pair<int,int>
#define vii vector<pii>
#define rep(i,a,b) for(int i=a; i<b; i++)
#define repr(b) for(int i=0; i<b; i++)
#define prin(vec) for(int i=0;i<vec.size();i++){cout<<vec[i]<<" ";}cout<<endl
#define newvec(x,n) vi x(n);rep(i,0,n){cin>>x[i];}
#define newvecn(x,n) int n;cin>>n;vi x(n);repr(n){cin>>x[i];}
#define float long double
#define vip vector<int>::iterator
#define mod 10000007
#define all(a) a.begin(),a.end()
#define ff first 
#define ss second 
#define pb push_back
#define neg cout<<"NO"<<endl;return;
#define pos cout<<"YES"<<endl;return;
#define pow(a,b) (int)pow(a,b)
#define intin(a) int a;cin>>a
#define mii map<int,int>
#define miv map<int,vi>
#define miit mii::iterator
#define mivt miv::iterator
#define matrix(x,n,m,g) vector<vi> x(n,vi(m,g)) 
 
bool sortbysec(const pair<int,int> &a, const pair<int,int> &b){                //to sort vii by second element use sort(v.begin(), v.end(), sortbysec);
    return (a.second < b.second);
}

int power(int x, int y){
    int k = 1;
    int p = 100000007;
    x = x%p;
    if(x==0){return 0;}
    while(y>0){
        if(y&1){
            k = (k*x)%p;
        }
        y = y>>1;
        x=(x*x)%p;
    }
    return k;
}

bool isPrime(int n)
{
    if (n <= 1)
        return false;
    for (int i = 2; i < n; i++)
        if (n % i == 0)
            return false;
    return true;
}

vi printPrime(int n){
    vi x;
    for (int i = 2; i <= n; i++) {
        if (isPrime(i))
            x.push_back(i);
    }
    return x;
}

bool vowel(char x){
    if(x=='a'||x=='u'||x=='o'||x=='i'||x=='e'){return 1;}
    return 0;
}

class node{
public:
    int data;
    node* left;
    node* right;
    node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

bool check_pali(int n){
    vi x;
    while(n){
        x.push_back(n%10);
        n/=10;
    }
    int i=0,j=x.size()-1;
    while(i<j){
        if(x[i]!=x[j]){return 0;}
        i++;j--;
    }
    return 1;
}

int size(int n){
    int a=0;
    while(n){
        a++;
        n/=10;
    }
    return a;
}

vi unique(vi x){
    map<int,int> mp;
    repr(x.size()){
        mp[x[i]]++;
    }
    map<int,int>::iterator it;
    vi ans;
    for(it=mp.begin();it!=mp.end();it++){
        ans.push_back(it->ff);
    }
    return ans;
}

vii unique_with_frequency(vi x){
    map<int,int> mp;
    repr(x.size()){
        mp[x[i]]++;
    }
    map<int,int>::iterator it;
    vii ans;
    for(it=mp.begin();it!=mp.end();it++){
        ans.push_back(make_pair(it->ff,it->ss));
    }
    return ans;
}

void solve(){
    newvecn(x,n);
    int a=0;
    repr(n){
        a = a^x[i];
    }
    if(a==0){
        pos;
    }
    int b=a;
    int i=0;
    for(i=i;i<n;i++){
        b = b^x[i];
        if(b==0){
            break;
        }
    }
    if(b){neg;}
    rep(j,i+1,n){
        a = a^x[j];
        if(a==0){
            break;
        }
    }
    if(a){neg;}
    pos;
}

signed main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t=1,curr=1;
    cin>>t;
    while (t--){
        //cout<<"Case #"<<curr++<<": ";
        solve();
    }
    return 0;
}



