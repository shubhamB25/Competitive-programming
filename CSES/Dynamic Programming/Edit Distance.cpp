#include <bits/stdc++.h>

using namespace std;

#define ll long long int

int solve(string &a, string &b)
{
    int n = a.size(), m = b.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            if(i == 0)
                dp[i][j] = j ; 
            else if(j == 0)
                dp[i][j] = i ; 
            else 
                dp[i][j] = min({dp[i][j-1]+1  , dp[i-1][j] + 1 , dp[i-1][j-1] + (a[i-1] == b[j-1] ? 0 : 1)})  ;
        }
    }
    //    for(int i = 0 ; i <= n ;i++){
    //     for(int j = 0 ;j <= m ;j++)
    //         cout<<dp[i][j] <<" " ; 
    //     cout<<endl;
    // }
    return dp[n][m] ; 
 
}

int main()
{
    string m, n;
    cin >> m >> n;
    cout << solve(m, n) << "\n";
}