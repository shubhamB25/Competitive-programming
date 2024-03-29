#include<bits/stdc++.h>



// Only return min in 0....r range

class FenwickTree
{
    vector<int> bit;
    int n;
    const int INF = (int)1e9;
public:
    FenwickTree(int n)
    {
        this->n = n + 1;
        bit.resize(n+1,INF);
    }
    FenwickTree(vector<int> a) : FenwickTree(a.size())
    {
        for(int i = 0; i < n; i++)
            update(i, a[i]) ;
    }

    int getmin(int r) {
        int ret = INF;
        for (; r >= 0; r -=  r & - r)
            ret = min(ret, bit[r]);
        return ret;
    }
    void update(int idx, int val)
    {
        for(++idx; idx < n; idx += idx & -idx)
        {
            bit[idx] = min(bit[idx] , val);
        }
    }
};
