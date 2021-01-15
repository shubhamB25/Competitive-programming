/* Idea : Simple dfs to find a loop.
* Loop is there if we visit a node which is already visited (since undirected)
* for this node can be the top level ancestor or a child so we find the starting path from path array
* and from this starting point till the end will be the circular path 
*/
#include <bits/stdc++.h>

using namespace std;

#define ll long long int;

vector<vector<int>> v;
vector<bool> vis;
int n, m;
// int ans;
vector<int> parent;
vector<int> a;
vector<int> path ; 

bool dfs(int i,  int parent  )
{
    vis[i] = true ; 
    path.push_back(i) ; 

    for(int x : v[i]){
        if(x == parent) continue ; 

        if(!vis[x]){
            dfs(x , i) ; 

        }else{ //loop found since it has already been visited
            path.push_back(x) ; 
            //find the starting point of the loop in the path 

            int j = find(path.begin() , path.end() , x) - path.begin() ; 
            cout<<path.size() -j  <<" \n" ; 
            for( ; j<(int) path.size() ; j++){
                cout<<path[j] <<" " ; 
            }
            exit(0) ; 
        }
    }
    path.pop_back() ; 
}

int main()
{
    cin.tie(NULL) ; 
    ios_base::sync_with_stdio(false);
    // freopen("input.txt", "r", stdin);
    cin >> n >> m;
    vis.resize(n + 1, false);
    v.resize(n + 1);
    parent.resize(n + 1, 0);
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;

        v[x].push_back(y);
        v[y].push_back(x);
    }
    for(int i= 1 ; i <= n ;i++){
        if(!vis[i]){
            dfs(i, 0) ; 
        }
    }
    cout<<"IMPOSSIBLE\n" ; 
    return  0; 
}