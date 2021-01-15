// dp[w][h] = minimum number of cuts needed to cut a w x h piece into squares.
#include <bits/stdc++.h>

using namespace std;

#define ll long long int;

const int mxx = 1e5 ; 

void solve(vector<int>& a,int n ){

    vector<vector<int>> dp(n+1, vector<int>(mxx+ 1, 0)) ; 

    for(int i = 1 ;i <=n ; i++)
    {
        for(int j = 0 ;j <= mxx ; j++)
        {

            //possible to build amount j with i coins 
            if(a[i-1] == j)
                dp[i][j] = 1;  
            else if(a[i-1] <= j)
                dp[i][j] = max(dp[i-1][j] , dp[i-1][j-a[i-1]]) ; 
            else
                dp[i][j] = dp[i-1][j] ; 
            

        }
    }

    // for(int i = 0 ; i<= n ;i++){
    //     for(int j = 0 ; j< 30 ; j++)
    //         cout<<dp[i][j] <<" " ; 
    //     cout<<endl;
    // }

    vector<int> ans ; 
    for(int i = 0 ;i <= mxx ; i++){
        if(dp[n][i] == 1)
            ans.push_back(i) ; 
    }

    sort(ans.begin() , ans.end())  ; 
    
    cout<<ans.size() <<"\n" ; 
    for(int i  : ans)
        cout<<i<<" " ; 
    cout<<endl;

    

}
int main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(NULL);
    int n ; 
    cin>> n; 
    vector<int> at(n+1) ; 
    for(int i = 0 ;i < n ;i++)
        cin>>at[i]  ; 

    solve(at , n) ; 
}