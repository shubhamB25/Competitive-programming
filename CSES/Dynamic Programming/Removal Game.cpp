#include<bits/stdc++.h>

using namespace std ;

#define ll long long int 

ll solve(vector< int > & a, int n ){
    
    vector<vector<long >> dp (n +1, vector<long>(n +1, 0)) ; 

// dp[l][r] = difference [score1−score2 ]if considering the game played only on interval [l, r].

    for(int l = n ; l > 0 ; l--){
        for(int r = l ; r<= n ;r++){
            if(r == l)
                dp[l][r] = a[r-1]  ; 
            else{
                dp[l][r] = max(dp[l-1][r]  +a[l], dp[l][r-1] + a[r]);
            }
        }
    }

      for(int i = 0 ;i <= n ;i++){
        for(int j = 0 ; j<=n ;j++){
            cout<<dp[i][j] <<" " ; 
        }
        cout<<endl; 
     }
     return dp[1][n]  ; 
}

int main(){
    int n ; 
    cin>>n ;
    vector<int> a(n, 0) ; 
    for(int i = 0 ; i< n ; i++)
        cin>>a[i] ; 
    cout<<solve(a, n ) <<"\n" ; 
}