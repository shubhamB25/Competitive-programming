/**
 * Count the number of ways to have sum n
 *  dp[0] =  1; by default there is way to get 0 
 * dp[i] = dp[i] + dp[i -coins[j]] 
 */
#include <bits/stdc++.h>

using namespace std;

#define ll long long int
const int mxN = 1e9 ; 
const int mod = 1e9 + 7 ; 
int main()
{
    int n, t;
    cin >> n >> t;

    vector<int> a(n );
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    vector<int> dp (t+1, 0) ; // for price t coing = dp[t]  ; 
    dp[0] = 1; 
    for(int i  = 1 ;i <=t ; i++){
        for(int j = 0 ; j< n ; j++)
        if(i >= a[j] ){
            dp[i] = (dp[i] + dp[i - a[j]] ) %mod  ; 
        }
    }
    cout<<dp[t] <<"\n" ; 

    // for(int i = 0 ; i < min(t, 100)  ;i++)
    //     cout<<dp[i]<<" " ; 
  
    

    return 0;
}
