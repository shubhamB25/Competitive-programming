#include<bits/stdc++.h>

using namespace std;

#define ll long long

class FenwickTree
{
    vector<ll> bit;
    int n ;
public :
    FenwickTree(int n )
    {
        this->n = n;
        bit.resize(n+1, 0) ;
    }
    FenwickTree(vector<ll> a ) : FenwickTree((int) a.size())
    {
        for(int i = 0 ;i < n;i ++)
            add(i , a[i]) ;
    }

    void add(int idx , int val)
    {
        ++idx;
        for(; idx <= n; idx += idx & -idx)
            bit[idx] += val ;
    }

    ll sum(int r)
    {
        ll ans = 0 ;
        while(r > 0)
        {
            ans += bit[r] ;
            r -= r & -r ;
        }
        return ans;
    }

    ll sum (int l , int r)
    {
        return sum(r) - sum (l -1) ;
    }

};


int main()
{
    int n ,q ;
    cin>>n>>q;
    vector<ll> a(n) ;
    for(ll &x : a) cin>>x ;

    FenwickTree ft(a);
    while(q--)
    {
        int z;
        cin>> z;
        if( z== 1)
        {
            int k, u ;
            cin>> k >> u ;
            ll delta = u - a[k-1] ;
            ft.add(k-1, delta) ;
            a[k-1] = u;
        }
        else
        {
            int x, y ;
            cin>>x >>y;
            cout<<ft.sum(x,y)<<"\n" ;
        }
    }
    return 0 ;
}
