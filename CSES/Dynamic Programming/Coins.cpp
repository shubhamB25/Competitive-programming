#include <bits/stdc++.h>

using namespace std;

#define ll long long int
const int mxN = 1e9 ; 
int main()
{
    int n, t;
    cin >> n >> t;

    vector<int> a(n );
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    vector<int> dp (t+1, mxN) ; // for price t coing = dp[t]  ; 
    dp[0] = 0 ; 
    for(int i  = 1 ;i <=t ; i++){
        for(int j = 0 ; j< n ; j++)
        if(i >= a[j] ){
            
            dp[i] = min(dp[i], dp[i- a[j]]+1) ; 
        }
    }

    // for(int i = 0 ;i<= t; i++){
    //     cout<<dp[i] <<" " ; 
    // }
    // cout<<endl; 
    cout<< (dp[t]== mxN ? -1 : dp[t] ) <<'\n' ; 
    

    return 0;
}
