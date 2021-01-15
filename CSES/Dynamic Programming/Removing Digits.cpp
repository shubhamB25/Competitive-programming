#include<bits/stdc++.h>

using namespace std; 

#define ll long long int

const int mxN = 2e6 ; 
const int mod = 1e9 + 7 ; 
int dp[mxN] ; 

int get_max(int n ){
	int temp = n ; 
	int ans = 0 ; 
	while(n >0){
		int r = n %10 ; 
		ans = max(ans, r) ; 
		n = n/ 10 ; 
	}
	return ans ; 
}
int main(){
	int n; 
	cin>> n; 
	dp[n] = 1; 
	for(int i = n ; i >0 ; ){
		int t= get_max(i) ; 
		i-= t ; 
		dp[i] = dp[i+t] + 1; 
	}
	cout<<dp[0]-1 <<"\n" ; 
	return 0 ; 
}
