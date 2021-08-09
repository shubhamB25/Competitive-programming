#include<bits/stdc++.h>

using namespace std;

class SegmentTreeMin{
    const int maxN = 2e5+5;
    const int INF = (int) 1e9 ;
    vector<int> tree;
    int n ;
    int getMin(int v, int tl, int tr, int l, int r)
    {
        if(l > r) return 0 ;
        if(l == tl  && tr == r)
            return tree[v];
        else
        {
            int tm = (tr - tl) / 2 + tl ;
            //return (getMin(v*2, tl , tm, l, min(tm, r)) + getMin(2*v +1 , tm+1, tr, max(tm+1, l) , r));
            return min(getMin(v*2, tl , tm, l, min(tm, r)) , getMin(2*v +1 , tm+1, tr, max(tm+1, l) , r));
        }
    }
public:
    SegmentTreeMin()
    {
        tree.resize(4*maxN, INF);
    }

    SegmentTreeMin(vector<int> &a, int n ) : SegmentTreeMin()
    {
        this->n = n;
        build(a, 1 , 0 , n-1);
    }

    void build(vector<int> &a, int v, int tl ,int tr)
    {
        if(tl == tr)
            tree[v] = a[tl];
        else
        {
            int tm = (tr - tl) / 2 + tl ;
            build(a, 2*v , tl , tm);
            build(a, 2*v +1 , tm+1 , tr);
            //tree[v] = tree[2*v] + tree[2*v +1]; // sum of left + right
            tree[v] = min(tree[2*v] ,tree[2*v +1]); // min of left + right
        }
    }
    int getMin(int l , int r)
    {
        return getMin(1, 1, n , l, r);
    }
};

int main()
{
    int n ,q;
    cin>> n >> q;
    vector<int> a(n) ;
    for(int i = 0; i < n; i++)
        cin>>a[i];

    SegmentTreeMin st(a,n);
    while(q--)
    {
        int x,y ;
        cin>>x >>y ;
        cout<<st.getMin(x,y)<<"\n";
    }
    return 0 ;
}



