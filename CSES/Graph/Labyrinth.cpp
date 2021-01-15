#include<bits/stdc++.h>

using namespace std ; 

#define ll long long int 

int dir[4][4] = { {1,0}, {-1,0} , {0, 1} , {0,-1}} ;

int main(){
	int H , W ; 
	cin>>H >> W ; 
	vector<string> a(H , string(W,'0')) ; 
	pair<int,int> start, ed ; 

	for(int i = 0 ;i < H ; i++){
		for(int j = 0 ;j < W ; j++){
			cin>>a[i][j] ; 
			if(a[i][j] == 'A') 
				start =  {i,j} ; 
			if(a[i][j] == 'B')
				ed = {i,j} ; 
				
		}
	}
	
	map<pair<int,int> , pair<pair<int,int>, char>> mp ; 

	queue<pair<int,int>> q ; 
	auto safe = [&] (int x , int y ){
		return x>= 0 && y>= 0 && x < H && y<W &&   a[x][y] != '#' ; 
	} ; 

	auto get_dir = [&] (int x ,int y ) {
		if(x == 1)	return 'D' ; 
		if(x== -1) return 'U' ; 
		if(y== 1) return 'R' ; 
		if(y== -1) return 'L' ; 
	} ;
	q.push(start) ; 
	bool found = false ; 	
	while (!q.empty())
	{
		auto fr = q.front() ; 
		q.pop() ; 
	
		if(fr == ed){
			found = true ; 
			break ; 
		}


		for( int i = 0 ; i< 4 ; i++){
			int x = fr.first + dir[i][0] ; 
			int y = fr.second + dir[i][1] ; 
			
			if(safe(x,y)){
				q.push({x,y}) ; 
				a[x][y] = '#' ; 
				char direction = get_dir(dir[i][0], dir[i][1])  ;
				mp[{x,y}] = {fr, direction} ; 
			}

			if(ed == make_pair(x,y)){
				found = true ; 
				break ; 
			}
			
		}
		if(found) break ; 
		
	}

	if(found){
		cout<<"YES"<<'\n' ; 
		string ans = "" ;
		pair<int,int> temp  = ed ;  
		while(temp != start){
			ans += mp[temp].second ;
			temp = mp[temp].first ;  
		}
		reverse(ans.begin() , ans.end()) ; 
		cout<<ans.size()<<'\n' ; 
		cout<<ans<<'\n' ; 
	}else{
		cout<<"NO\n" ; 
	}


	
	
}