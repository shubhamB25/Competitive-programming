#include <bits/stdc++.h>
using namespace std;

template<typename... T>
void read(T&... args) {
    ((cin >> args), ...);
}

template<typename... T>
void write(T&&... args) { //rvalue reference is new to C++ 
    ((cout << args << " "), ...);
    cout<<endl;
}

const int MOD = 1e9 + 7;
#define cer(x) cerr<<#x<<"="<<x<<'\n'
#define deb(x) cout<<#x<<"="<<x<<'\n'
#define deb2(x,y) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<'\n'
#define deb3(x,y,z) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<","<<#z<<"="<<z<<'\n'
#define fo(i, n) for(i=0; i<n; i++)
#define Fo(i, k, n) for(i=k; i<n; i++)
#define ll long long int
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pb push_back
#define eb emplace_back
#define ff first
#define ss second
#define vi vector<int>
#define vl vector<ll>
#define vpii vector<pii>
#define vpll vector<pll>
#define si set<int>
#define mpii map<int, int>
#define prq priority_queue
#define sz(s) (int) s.size()
#define pf(a) printf("%d\n",a)
#define sc1(a) scanf("%d",&a)
#define sc2(a, b) scanf("%d%d",&a,&b)
#define pi 2 * acos (0.0)
#define inf 1e9
#define dbg cout<<"ok"<<endl;
#define FOR(i, j, k) for(int i=(j); i<(k); i++)
#define REV(i, j, k) for(int i=(n-1); i>=k; i--)
#define rnd(a, b) ((((rand()<<15)^rand())%((b)-(a) + 1))+(a))
#define FAST_IO ios_base::sync_with_stdio(false),cin.tie(NULL)
#define mem(x, y) memset(x, y, sizeof(x))
const double EPS = 1e-9;
const int MXX = 1e5 + 5;


int main()
{
    FAST_IO;
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    int n ;     
    cin>>n;
    map<int,int> mp  ; 
    int i , j ; 
    vi a(n) ; 
    fo(i,n)
        cin>>a[i] ; 
    
    j = 0 ; 
    int m = -1 ; 
    int ans = 0 ; 
    fo(i ,n){
        if(mp.find(a[i]) == mp.end()){
            m = - 1; 
        }else{
            m = mp[a[i]] ; 
        }
        j = max( j , m + 1) ; // if m==-1 then we stay at 0 
        
        ans = max(ans, i -j +1) ; 
        mp[a[i]] = i ;
    }
    

    cout<<ans<<endl; 
        return 0;
}

// =  > to avoid uisng mp.find() use the below method 


/*
 *  Basically we use index from 1 to over come find becuase then is won't clash wiht
 *  0 when mp [a[i]] is empty.
 */
 
// nt n;
//  cin>>n;
//  map<int,int>lastind;
//  int a[n+1];
//  for(int i=1;i<=n;i++)
//  {
//   cin>>a[i];
//  }
//  int i=1,ans=0;
//  for(int j=1;j<=n;j++)
//  {
//   i=max(i,lastind[a[j]]+1);
//   ans=max(ans,j-i+1);
//   lastind[a[j]]=j;
//  }

//  cout<<ans<<endl;