#include<bits/stdc++.h>

using namespace std; 

#define ll long long int

const int mxN = 2e6 ; 
const int mod = 1e9 + 7 ; 
int dp[mxN] ; 

int main(){
    int  k , n ; 
    cin>> k >> n; 
    vector<int> a ( k) ; 
    for(int i = 0 ;i< k ; i++)
        cin>>a[i] ; 
    
    dp[0] = 1 ;
    for(int i = 0 ; i <k; i++){
        for(int j = 1  ; j<= n ; j++){
            if( j>= a[i] ){
                dp[j] = (dp[j] + dp[j- a[i]]) % mod ; 
            }
        }
    }
    cout<<dp[n] <<"\n" ; 
}