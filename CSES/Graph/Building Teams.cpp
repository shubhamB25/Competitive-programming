/* Simple Program to find whether the given graph is bipartite graph or not */
#include<bits/stdc++.h>

using namespace std ; 

#define RED  1 
#define BLUE  0 ;  

#define ll long long int 
vector<vector<int>> v ; 
vector<int> color ;
int m , n ;

bool util(int i, vector<int> &color ){
    color[i] = RED ; 
    queue<int> q ; 
    q.push(i) ; 
    while (!q.empty())
    {
       int u = q.front() ; 
       q.pop() ; 
       for(int x  : v[u]){
           if(x == u )
           return false ; 
           if(color[x] == -1){
               color[x] = 1^ color[u] ; 
               q.push(x) ; 
           }
       if(color[x] == color[u])
            return false ; 
       } 


    }
    return true  ; 
    
}
bool bipartate(){ 

    
    for(int i = 1 ; i<= n ;i++){
        //here color acts as vis array 
        if(color[i] == -1)
            if(!util(i, color)) return false ; 
    }
    return true ; 
}



int main(){
    cin>> n>> m ; 
    v.resize(n+1) ; 
    color.resize(n+1, -1) ; 
    for(int i = 0 ; i<m ; i++){
        int x, y ; 
        cin>> x>> y ; 
        v[x].push_back(y) ; 
        v[y].push_back(x) ; 
    }


    if(bipartate()){
        
        for(int i = 1 ; i<= n ;i ++)
            cout<<color[i] +1<<" " ; 
    }else{
        cout<<"IMPOSSIBLE\n" ; 
    }



}