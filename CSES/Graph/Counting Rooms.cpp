#include <bits/stdc++.h>

using namespace std;

#define ll long long int
int H, W, n, m;
bool safe(vector<string> &a, int H, int W, int x, int y)
{
	return x >= 0 && y >= 0 && x < H && y < W && a[x][y] != '#';
}
vector<pair<int, int>> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

bool safe(int x, int y , vector<string> &a)
{
	return x >= 0 && x < H && y >= 0 && y < W && a[x][y] != '#';
};

void dfs(int x ,int y , vector<string>& a ){
	a[x][y] = '#' ; 

	for(auto t: dir){
		int n = t.first + x ;
		int m = t.second + y ; 
		if(safe(n , m , a) )
			dfs(n , m , a) ; 
	}
}

int main()
{
	cin >> H >> W;
	vector<string> a(H);
	for (int i = 0; i < H; i++){
		string s ; 
		cin>> s ; 
		a[i] = s ; 
	}


	auto safe = [&](int x, int y) {
		return x >= 0 && x < H && y >= 0 && y < W && a[x][y] != '#';
	};

	ll ans = 0;
	vector<vector<int>> dp(H, vector<int>(W, 0));
	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < W; j++)
		{

			if (a[i][j] == '.')
			{
				dfs(i ,j, a) ; 
				ans++ ; 
			}
		}
	}
	cout << ans << "\n";
	return 0;
}
