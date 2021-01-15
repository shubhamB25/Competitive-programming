#include<bits/stdc++.h>

using namespace std ; 

#define ll long long int 
vector<vector<int>> v ; 
int main(){
    int m , n ; 
    cin>> n>> m ; 
    v.resize(n+1) ; 
    for(int i = 0 ; i<m ; i++){
        int x, y ; 
        cin>> x>> y ; 
        v[x].push_back(y) ; 
        v[y].push_back(x) ; 
    }

   int parent[n+1] , dis[n+1]  ; 
    bool vis[n+1] ; 
    for(int i = 0 ; i<= n ;i++)
    {
        dis[i] = -1 ; 
        parent[i] = -1 ; 
        vis[i] = false ; 
    } 
    queue<int> q ; 
    q.push(1) ; 
    dis[1] = 1 ; 
    parent[1] = 1 ; 
    vis[1] = true ; 
    while(!q.empty()){
        int fr = q.front() ;
        q.pop() ; 
        for(int x : v[fr]){
            if(vis[x] == false){
                q.push(x) ; 
                parent[x] = fr ; 
                dis[x] = dis[fr] + 1 ; 
                vis[x] = true ; 
            }
        }
    }

    if(parent[n] == -1)
    {
        cout<<"IMPOSSIBLE\n" ; 
    }else{
        cout<<dis[n] <<"\n" ; 
        int x = n ;
        vector<int> s ;   
        while(x !=1 ){
            s.push_back(x) ;  
            x = parent[x] ; 
        }
        s.push_back(1) ; 
        reverse(s.begin() , s.end()) ; 
        for(int x : s){
            cout<<x<<" " ; 
        }


        
    }

}