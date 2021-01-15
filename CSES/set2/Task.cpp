

#include <bits/stdc++.h>

using namespace std;

#define ll long long int
bool comp(vector<int> &a, const vector<int> &b)
{
    if ((a[1] - a[0]) == (b[1] - b[0]))
    {
        return a[0] < b[0];
    }
    return (a[1] - a[0]) > (b[1] - b[0]);

}

bool comp2(const vector<int> & a , const vector<int> & b){
    return a[1] < b[1] ; 
}
int main()
{
    int n;
    cin >> n;

    vector<int> a[n];

    for (int i = 0; i < n; i++)
    {
        int s, d;
        cin >> s >> d;
        a[i] = {s, d};
    }

    sort(a, a + n, comp2);
    ll count=0 ; 
    ll ans = 0 ; 
    for (int i = 0; i < n; i++)
    {
        printf("s : %d , d = %d\n", a[i][0] , a[i][1] );
        ll fin = count +  a[i][0] ; 
        ans += a[i][1] - fin ; 
        printf("finish = %d, end = %d\n" , a[i][0] + count, ans) ; 

        count = fin ; 
    }
    cout<<ans<<"\n" ;
}