#include<bits/stdc++.h>

using namespace std; 

#define ll long long int ; 

const int mxN = 2e5 ;
array<int,3 > a[mxN] ; 

int main(){
    int n ; 
    cin>>n ; 

    for(int i = 0 ;i< n ;i++){
        cin>>a[i][1]>>a[i][0] ; 
        a[i][2]= i ; 
    }
    vector<int> ans(n) ; 
    sort(a, a+n) ; 
    set<array<int,3>> s; 
    for(int i = 0 ;i<n ;i++){
        auto it = s.lower_bound({a[i][1]}); 
        
        if(it != s.begin()){
            it-- ; 
            ans[a[i][2]] = (*it)[1] ; 
            s.erase(it) ;
        }
        else{
             ans[a[i][2]] = s.size() ;
              
        }
        s.insert({a[i][0], ans[a[i][2]] }) ; 
    }
    cout<<s.size()<<endl; 
    for(int x : ans){
        cout<<x+1<<" " ; 
    }
    cout<<"\n" ; 
    return 0 ; 
}
