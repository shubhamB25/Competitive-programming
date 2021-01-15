#include<bits/stdc++.h>

using namespace std; 

#define ll long long int

const int mxN = 2e6 ; 
const int mod = 1e9 + 7 ; 
// int dp[mxN] ; 
const int mxx = 1000  ; 

int main(){
    int n , t ; 
    cin>>n >> t; 
    vector<int> pr(n ) , pg(n) ; 
    for(int i  = 0 ; i < n ;i++)
        cin>>pr[i] ; 
    for(int i = 0 ; i < n ; i++)
        cin>>pg[i] ; 


    /*  1D implementation */
    // vector<int> dp(t+1) ; 
    //  for(int i = 0 ;i  < n; i ++){
    //     for(int j = t ; j >= pr[i]; j--){ // to avoid using 2d array we count from backward
    //             dp[j] = max(dp[j] , dp[j - pr[i]] + pg[i]) ; 
    //     } 
    // }
    vector<vector<int>> dp(n+ 1 , vector<int>(t+1 , 0)) ; 

    for(int i = 0 ;i  <= n; i ++){
        for(int j = 1 ; j<=  t; j++){
            if(i == 0 || j == 0 )
                continue ; 
            else if (pr[i-1] <= j)
            {
                dp[i][j] = max(pg[i-1] + dp[i-1][j- pr[i-1]], dp[i-1][j]);
            }else{
                dp[i][j]= dp[i-1][j] ; 
            }
        }
    
    }
    cout<<dp[n][t]<<"\n" ; 
    for(int i = 0 ;i  <= n; i ++){
        for(int j = 1 ; j<=  t; j++){
            cout<<dp[i][j] <<" " ; 
        }
        cout<<endl; 
    }
    
    
    return 0 ; 
}