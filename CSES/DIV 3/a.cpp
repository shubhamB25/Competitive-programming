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
const int nax = 10000 ; 

int a[10000] ;  
vector<int> ans ; 
void seive(){
    ll sum = 0 ; 
    for(int i = 1 ; i < 10 ; i ++){
        int curr = i ; 
        while(curr < nax){
            sum += log10(curr) +1 ; 
            a[curr] = sum ; 
            curr = curr *10 + i;  
        }

    }
}

int main()
{
    FAST_IO;
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    ll n ; 
    seive() ; 
    int t ; 
    cin>> t ;
    while(t--){
        cin>>n ; 
        cout<<a[n] <<endl ; 
    }

    return 0;
}