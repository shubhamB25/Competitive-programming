#include <bits/stdc++.h>

using namespace std;

#define ll long long int;

int dir[4][2] = {{0,1} , {1,0}, {-1,0} , {0,-1}} ; 
#define EMPTY  (int)1e7
vector<string> g ; 
vector<vector<int>> v;
vector<bool> vis;
pair<int,int> start ; 
vector<vector<int>> dis(1001, vector<int>(1001, EMPTY)) ; 
int H , W ; 

bool end(int x ,int y){
    return x== 0 || y == 0 ; 
}

char direction(int x ,int y){
    if(y==1){
        return 'R' ; 
    }
    if(y == -1) return 'L'; 
    if(x==1) return 'D' ; 
    if(x==-1) return 'U' ; 
    return 'x' ; 
}

int main(){
    // freopen("input.txt" , "r", stdin) ;
    cin>>H ; 
    cin>>W ; 
    
    g.resize(H , string(W , '#')) ; 
    queue<pair<pair<int,int> , int>> monsters ;  
    for(int i = 0 ; i < H; i++){
        for(int j= 0 ; j < W ; j++){
            cin>>g[i][j] ; 
            if(g[i][j] == 'A'){
                start = {i, j} ; 
            }
            else if(g[i][j] == 'M'){
                dis[i][j] = 0 ; 
                monsters.push({{i,j},1})  ; 
            }
        }
    }

    auto safe = [&](int x, int y){ return x>=0 && y>=0 && x< H && y < W && g[x][y] != '#';} ; 
    while(!monsters.empty()){
        auto fr = monsters.front() ; 
        monsters.pop() ;
        int step = fr.second ; 

        for(int i = 0 ;i < 4 ; i++){
            int x= dir[i][0]+fr.first.first ; 
            int y = dir[i][1] + fr.first.second; 
            if(safe(x,y) && dis[x][y] > step){
                dis[x][y] = step ; 
                monsters.push({{x,y} , step+1}) ; 
            }
        }

    }
    bool flag = false ; 
    queue<pair<pair<int,int> , int>> q ; 
    map<pair<int,int>, pair<pair<int,int>, char>> mp ; 
    q.push({{start} , 1}) ; 
    pair<int,int> end ;
    while(!q.empty()){
        auto fr = q.front() ; 
        q.pop() ; 
        int step = fr.second ; 
        if(fr.first.first == 0 || fr.first.second == 0 || fr.first.first == H-1 || fr.first.second == W-1){
            end = fr.first ; 
            flag = true ; 
            break ; 
        }
        for(int i = 0 ;i < 4 ; i++){
            int x  = dir[i][0] + fr.first.first ; 
            int y = dir[i][1] +fr.first.second ; 
            if(safe(x,y) && dis[x][y] > step){
                dis[x][y] = step ; 
                mp[{x,y}] = {{fr.first}, direction(dir[i][0],dir[i][1])} ; 
                q.push({{x,y} , step+1}) ; 

            }
        }
    }
    if(flag){
        cout<<"YES\n" ; 
        string ans ="" ; 
        
        int step = 0 ; 
        while(end != start){
            ans += mp[end].second ; 
            end = mp[end].first ; 
            step ++ ; 
        }
        cout<<step<<"\n" ; 
        reverse(ans.begin() , ans.end()) ; 
        cout<<ans<<"\n" ; 
    }
    else{
        cout<<"NO\n" ; 
    }
    
 
    return 0 ; 
}