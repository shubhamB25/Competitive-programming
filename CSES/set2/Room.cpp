#include<bits/stdc++.h>

using namespace std; 

#define ll long long int ; 

int main(){
    int n ; 
    cin>>n ; 
    vector<vector<int>> a ; 
    for(int i = 0 ;i <n ;i++)
    {
        int temp ; 
        cin>>temp ; 
        a.push_back({temp , 1 , i}); 
        cin>>temp ; 
        a.push_back({temp , 0 , i })  ; 
    }
    sort(a.begin() , a.end()) ; 
    int ans = 0 , curr = 1 ; 
    vector<int> room (n) ; 
    for(auto t : a){
        if(t[1] ==1){
            curr++ ; 
            room[t[3]] = curr ; 
        }else{

            curr-- ; 
        }
        ans = max(ans, curr) ; 
    }
    cout<<ans <<"\n"  ; 
    for(int i : room)   
        cout<<i<<" " ; 


   return 0 ; 
}
