#include <bits/stdc++.h>

using namespace std;

#define ll long long int;

int dir[4][4] = {{0,1} , {1,0}, {-1,0} , {0,-1}} ; 
#define EMPTY  1e9 
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
        return 'L' ; 
    }
    if(y == -1) return 'R'; 
    if(x==1) return 'D' ; 
    if(x==-1) return 'U' ; 
    return 'x' ; 
}

int main(){

    cin>> H >> W ;

    g.resize(H , string(W , '#')) ; 
    queue<pair<int,int>> monsters ;  
    for(int i = 0 ; i < H; i++){
        for(int j= 0 ; j < W ; j++){
            cin>>g[i][j] ; 
            if(g[i][j] == 'A'){
                start = {i, j} ; 
            }
            else if(g[i][j] == 'M'){
                monsters.push({i,j})  ; 
            }
        }
    }
 

    auto safe = [&](int x, int y){ return x>=0 && y>=0 && x< H && y < W && g[x][y] != '#';} ; 

    while(!monsters.empty()){
        auto fr = monsters.front() ; 
        monsters.pop() ; 
        queue<pair<pair<int,int> , int>> q ; 
        q.push({fr,0}) ; 
        while(!q.empty()){
            auto slot = q.front().first ;
            int step =q.front() .second ;  
            q.pop() ;
            for(int i = 0 ;i < 4 ; i++){
                int x = slot.first + dir[i][0] ; 
                int y = slot.second + dir[i][1] ; 
                if(safe(x,y) &&  dis[x][y] > step){
                    q.push({{x,y}, step+1}) ; 
                    dis[x][y] = step ; 

                }
            }
        }
    }


    //all the monster paths have been updates. Find if the person can reach slot g[i][j] before any other person 
    queue<pair<pair<int,int> , int>> q ; 
    q.push({start, 0}) ; 
    pair<int,int> end ; 
    bool flag = false ; 
    map<pair<int,int> , pair<pair<int,int> , char>> mp ; 
    while (!q.empty())
    {
        auto fr = q.front().first ; 
        if(fr.second == 0 || fr.first == 0){
            end = fr ; 
            flag = true ; 
            break ; 
        }
        int step = q.front().second ;
        q.pop() ;  
        for(int i = 0 ; i<4 ; i++){
            int x= fr.first + dir[i][0] ; 
            int y = fr.second + dir[i][1] ; 
            if(safe(x,y) &&  dis[x][y] > step){
                mp[{x,y}] ={fr , direction(dir[i][0], dir[i][1])} ; 
                q.push({{x,y} , step}) ; 
            }
        }

    }
    if(flag){
        cout<<"YES\n" ; 
        string ans ="" ; 
        int count = 0 ; 
        while(end != start){
            ans += mp[end].second ; 
            end = mp[end].first ; 
            count++ ; 
        }
        cout<<count<<"\n" ; 
        cout<<ans<<"\n" ; 
    }else
    {
        cout<<"IMPOSSIBLE\n" ; 
    }
    for(int i = 0 ;i< 5 ;i++){
        for(int j = 0 ; j< W ; j++){
            if(dis[i][j] != EMPTY)
            cout<<dis[i][j]<<" " ;
            else
                cout<<0<<" " ;  

        }
        cout<<endl ; 
    }
    return 0 ; 

}