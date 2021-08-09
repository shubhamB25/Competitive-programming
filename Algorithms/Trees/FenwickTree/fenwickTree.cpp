#include<bits/stdc++.h>

class FenwickTree
{
    vector<int> bit;
    int n;
public:
    FenwickTree(int n)
    {
        this->n = n + 1;
        bit.resize(n+1,0);
    }
    FenwickTree(vector<int> a) : FenwickTree(a.size())
    {
        for(int i = 0; i < n; i++)
            add(i, a[i]) ;
    }

    int  sum(int r)
    {
        int ans = 0;
        while(r > 0)
        {
            ans += bit[r];
            r -= r & -r;
        }
        return ans;
    }
    int sum(int l , int r)
    {
        return sum(r) - sum(l-1);
    }
    void add(int idx, int delta)
    {
        for(++idx;  idx < n; idx += idx & -idx)
        {
            bit[idx] += delta;
        }
    }
};
