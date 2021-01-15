// dp[w][h] = minimum number of cuts needed to cut a w x h piece into squares.
#include <bits/stdc++.h>

using namespace std;

#define ll long long int;

int solve(int W, int H)
{
    if (H == W)
        return 0;
    vector<vector<int>> dp(W + 1, vector<int>(H + 1, 0));

    for (int i = 0; i <= W; i++)
    {
        for (int j = 0; j <= H; j++)
        {
            if (i == j)
                dp[i][j] = 0;
            else
            {
                dp[i][j] = 1e9;
                for (int k = 1; k < i; k++)
                {
                    dp[i][j] = min(dp[i][j], dp[i - k][j] + dp[k][j] + 1);
                }

                for (int k = 1; k < j; k++)
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[i][j - k] + 1);
                for (int k = 1; k < i; k++)
                {
                    dp[i][j] = min(dp[i][j], dp[k][j] + dp[i - k][j] + 1);
                }
                for (int k = 1; k < j; k++)
                {
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[i][j - k] + 1);
                }
            }
        }
    }

    // for (int i = 0; i <= W; i++)
    // {
    //     for (int j = 0; j <= H; j++)
    //         cout << (dp[i][j] == 1e9 ? 0 : dp[i][j]) << " ";
    //     cout << endl;
    // }
    return dp[W][H];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int w ,h ; 
    cin>> w >> h ; 
    cout << solve(w, h) << "\n";
}