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
#define pqi priority_queue<int>
 
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


int findEntryWithLargestValue(map<float,int> sampleMap){

	pair<float,int> entryWithMaxValue = make_pair(0.0, 0);

	// Iterate in the map to find the required entry
	map<float,int>::iterator currentEntry;
	for (currentEntry = sampleMap.begin();
		currentEntry != sampleMap.end();
		++currentEntry) {

		if (currentEntry->second > entryWithMaxValue.second) {

			entryWithMaxValue
				= make_pair(
					currentEntry->first,
					currentEntry->second);
		}
	}

	return entryWithMaxValue.ss;
}

bool finder(pair<int,vi> biguse[],pair<int,vi> bigsend[],string &t,int k,int prev,int n){
    if(k>=(int)t.size()){
        if((n-prev)%2){return true;}
        return false;
    }
    if(biguse[t[k]-'a'].ff >= (int)biguse[t[k]-'a'].ss.size()){return false;}
    int x = biguse[t[k]-'a'].ff;
    int i = x;
    int m = biguse[t[k]-'a'].ss.size();
    while(i<m){
        if(biguse[t[k]-'a'].ss[i]>prev){
            biguse[t[k]-'a'].ff=i+1;
            if(finder(bigsend,biguse,t,k+1,biguse[t[k]-'a'].ss[i],n)){return true;}
            break;
        }
        i++;
    }
    biguse[t[k]-'a'].ff=x;
    return false;
}

void solve(){
    int n,k;cin>>n>>k;
    newvec(a,k);
    newvec(t,k);
    vii al;
    repr(k){
        al.pb(make_pair(a[i],t[i]));
    }
    sort(all(al));
    stack<int> x,y;
    repr(k){
        while(!x.empty() && al[x.top()].ss >= (al[i].ss+al[i].ff-al[x.top()].ff)){
            x.pop();
        }
        x.push(i);
    }
    while(!x.empty()){
        int a = x.top();
        x.pop();
        while(!y.empty() && al[y.top()].ss >= (al[a].ss+abs(al[a].ff-al[y.top()].ff))){
            y.pop();
        }
        y.push(a);
    }
    while(!y.empty()){
        x.push(y.top());
        y.pop();
    }
    vi ans(n);
    rep(i,al[x.top()].ff-1,n){
        ans[i] = al[x.top()].ss + i-al[x.top()].ff+1;
    }
    int l = x.top();
    x.pop();
    int r;
    while(!x.empty()){
        r = l;
        l = x.top();
        int i = al[r].ff-1;
        while(i>=al[l].ff){
            ans[i-1] = min(al[r].ss + abs(i-al[r].ff),al[l].ss + abs(i-al[l].ff));
            i--;
        }
        x.pop();
    }
    repr(al[l].ff){
        ans[i] = al[l].ss + abs(i-al[l].ff+1);
    }
    prin(ans);
    return;
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



