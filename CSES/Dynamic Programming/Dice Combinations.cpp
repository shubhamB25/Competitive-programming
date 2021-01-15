#include<bits/stdc++.h>

using namespace std ; 

#define ll long long int 

const int mod = 1e9+  7 ; 

int main(){
    int n ; 
    cin>> n; 
    vector<long long int>  dp(n+6) ; 
    dp[1] = 1 ; 
    dp[2] = 2 ; 
    dp[3] = 4 ; 
    for(int i = 4 ; i<= 6 ; i++){
        dp[i] = 1 ; 
    }
    for(int i = 4 ; i <= n ; i++){
        if(i<5){
            dp[i] += dp[i-1] + dp[i-2] + dp[i-3] + dp[ i -4]  ; 
        }
        else if(i < 6){
            dp[i] += dp[i-1] + dp[i-2] + dp[i-3] + dp[ i -4] + dp[i-5] ;
        }
        else
            dp[i] += dp[i-1] + dp[i-2] + dp[i-3] + dp[ i -4] + dp[i-5] + dp[i-6 ] ; 
        
        dp[i] %= mod ; 
    }
    cout<<dp[n] % mod<<endl; 
    return 0 ;
}



