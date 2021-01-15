#include <bits/stdc++.h>
using namespace std;

template <typename... T>
void read(T &... args)
{
    ((cin >> args), ...);
}

template <typename... T>
void write(T &&... args)
{ //rvalue reference is new to C++
    ((cout << args << " "), ...);
    cout << endl;
}

const int MOD = 1e9 + 7;
#define cer(x) cerr << #x << "=" << x << '\n'
#define deb(x) cout << #x << "=" << x << '\n'
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << '\n'
#define deb3(x, y, z) cout << #x << "=" << x << "," << #y << "=" << y << "," << #z << "=" << z << '\n'
#define fo(i, n) for (i = 0; i < n; i++)
#define Fo(i, k, n) for (i = k; i < n; i++)
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
#define sz(s) (int)s.size()
#define pf(a) printf("%d\n", a)
#define sc1(a) scanf("%d", &a)
#define sc2(a, b) scanf("%d%d", &a, &b)
#define pi 2 * acos(0.0)
#define inf 1e9
#define dbg cout << "ok" << endl;
#define FOR(i, j, k) for (int i = (j); i < (k); i++)
#define REV(i, j, k) for (int i = (n - 1); i >= k; i--)
#define rnd(a, b) ((((rand() << 15) ^ rand()) % ((b) - (a) + 1)) + (a))
#define FAST_IO ios_base::sync_with_stdio(false), cin.tie(NULL)
#define mem(x, y) memset(x, y, sizeof(x))
const double EPS = 1e-9;
const int MXX = 1e5 + 5;

const int mxN = 1e5 + 5;
const int mxM = 2e5 + 5;

vector<bool> vis(mxN, false);
vector<vector<int>> v  ; 
ll ans  ; 

void dfs (int idx, int n ) {
    vis[idx] = true ; 
    for(int x : v[idx]){
        if(vis[x] == false){
            dfs(x , n) ; 
        }
    }
};
  
int main()
{
    FAST_IO;
    // freopen("input.txt", "r" , stdin) ;

    int n, t, i, j, k;
    int m;
    cin >> n >> m;

    v.resize(n+1) ; 
    

    for (int i = 0; i < m; i++)
    {

        int x, y;
        cin >> x >> y;
        v[x].push_back(y) ; 
        v[y].push_back(x) ; 
    }
    vector<int> s ; 

    queue<int> q ; 
    for(int i = 1 ; i <= n ;i ++){
    {
        if(vis[i] == false){
            vis[i] = true ;
            ans ++ ; 
            s.push_back(i) ; 
            q.push(i) ; 
            while(!q.empty()){
                auto fr = q.front() ; 
                q.pop(); 
                for(int x : v[fr]){
                    if(vis[x] == false){
                        vis[x] = true ; 
                        q.push(x) ; 
                    }
                }
            }
        }
    }
    }
    for(int i = 0 ;i < n;i++){

    }


    cout<<ans-1 <<endl; 
    for(int i =  0 ;i < (int) s.size() -1;i ++){
        cout<<s[i]<<" " <<s[i+1] <<endl; 
    }
    return 0;
}