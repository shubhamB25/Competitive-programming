#include<bits/stdc++.h>

using namespace std ;

#define ll long long

vector<int> rabin_karp(string const & s , string const & t) // s => patter, t= text
{
    int n = s.size() ;
    int m =t.size() ;
    const int p = 31 ;
    const int MOD = 1e9 + 9 ;
    vector<ll> p_pow(m) ;
    p_pow[0] = 1;
    for(int i = 1 ;i <= m ; i++)
        p_pow[i]  = (p_pow[i-1] * p) %MOD ;

    vector<ll> h(m+1, 0) ;
    for(int i  = 1 ;i <= m ;i ++)
        h[i] = (h[i-1] + (t[i-1] - 'a' + 1) * p_pow[i-1]) % MOD ;
    ll h_s = 0 ;
    for(int i = 0 ;i < n ; i++)
        h_s = (h_s + (s[i] - 'a' +1 )*p_pow[i])%MOD ;
    vector<int> occurences ;
    for(int i = 0 ;i + n -1  < m ; i++)
    {
        ll curr = (h[i+n] - h[i] + MOD ) % MOD ;
        if(curr == h_s * p_pow[i] %MOD ) occurences.push_back(i) ;
    }
    return occurences ;
}



int main()
{
    auto ans = rabin_karp("pp", "saippuakauppias" );
    for(auto it : ans) cout<<it<<" " ;
    return 0 ;
}

