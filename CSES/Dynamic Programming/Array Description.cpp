#include <bits/stdc++.h>

using namespace std;

#define ll long long int

const int mxN = 2e5 + 7;
const int mxx = 101;
const int mod = 1e9+7 ;

ll solve(vector<int> &a, int n, int m)
{
	vector<vector<int>> dp(n+2 , vector<int>(m+2, 0)) ; 
	

	for (int i = 1; i <= n; i++)
	{

		for (int j = 1 ;  j <= m; j++)
		{
			if(i == 1 ){
				if(a[i] == 0 || a[i] == j ) 
					dp[i][j] = 1; 
				else
					dp[i][j] = 0 ; 
			}
			else{
				if(a[i] == 0 || a[i] == j )
					dp[i][j] = ((dp[i - 1][j]  + dp[i - 1][j - 1])%mod + dp[i-1][j + 1]) %mod ;
				else
					dp[i][j] = 0 ; 
			}
		}
	}

	// for (int i = 1; i <= n; i++)
	// {
	// 	for (int j = 1; j <= m; j++)
	// 	{
	// 		cout << dp[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }
	ll ans = 0;
	for (int i = 1; i <=m; i++)
	{
		ans =(ans +dp[n][i] )% mod;
	}
	return ans;
}

int main()
{
	ios::sync_with_stdio(false) ; 
	cin.tie(NULL) ; 
	int n, m;
	cin >> n >> m;

	vector<int> a(n +1, 0);

	for(int i = 1; i<=n ;i++)
		cin>>a[i] ; 


	cout << solve(a, n, m) << "\n";

	return 0;
}
