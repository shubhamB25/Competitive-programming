#include<bits/stdc++.h>

using namespace std; 

#define ll long long int

const int mxN = 2e6 ; 
const int mod = 1e9 + 7 ; 
// int dp[mxN] ; 
const int mxx = 1000  ; 
int n; 
vector<vector<int>> dp(mxx+1, vector<int>(mxx+1)) ; 
vector<vector<bool>> visited(mxx+1, vector<bool>(mxx+1)) ; 



bool safe(vector<string> & a, int row , int col ){
	return row >=0 && col >= 0 &&row < n && col < n && visited[row][col] == false && a[row][col] != '*' ; 
}

void util(vector<string> & a, int row ,int col){
	if(row == n-1 && col == n-1){
		dp[n-1][n-1]++ ; 
		return  ; 
	}
	visited[row][col] = true ; 
	if(safe(a, row+1 , col)){
		// dp[row+1][col] += dp[row][col]+ 1 ; 
		// dp[row+1][col] %= mod ; 
		util(a, row+1 , col); 
	}
	if(safe(a, row, col+1)){
		// dp[row][col+1] += dp[row][col] +1 ; 
		// dp[row][col+1] %= mod ; 
		util(a, row, col+1) ; 
	}
	visited[row][col] = false ; 
}






int find_path(vector<string> & a){
	util(a , 0 ,0) ; 
	return dp[n-1][n-1] ; 
}


int main(){
	cin>> n; 
	vector<string> a(n)  ; 
	for(int i = 0 ;i< n; i++){
		cin>>a[i] ; 
	} 

	dp[0][0] = a[0][0] == '.' ? 1 : 0 ; 
	for(int row = 0 ; row < n ; row++){
		for(int col = 0 ; col < n ; col++){
			if(safe(a , row -1 , col ) && a[row][col] != '*')
				dp[row][col] = (dp[row][col] +dp[row-1][col] ) %mod ; 
			if(safe(a, row , col -1 ) && a[row][col] != '*')
				dp[row][col] = (dp[row][col] +dp[row][col-1] ) %mod ; 

				// dp[row][col] ++ ; 
			
		}
	}
	cout<<dp[n-1][n-1] <<"\n" ; 

	// for(int row = 0 ; row < n ; row++){
	// 	for(int col = 0 ; col < n ; col++){
	// 		cout<<dp[row][col]<<" " ; 
	// 	}
	// 	cout<<endl; 
	// }

	return 0 ; 
}
