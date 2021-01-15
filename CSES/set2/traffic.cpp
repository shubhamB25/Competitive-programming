#include<bits/stdc++.h>
 
using namespace std; 
 
#define ll long long int
ll find(set<int> s ,int n,int x  ){
    ll last  = 0 ; 
    ll ans = 0 ; 
    for(int x : s){
        ans = max(x - last , ans) ; 
        last = x ; 
    }
    ans = max(x -last ,ans) ; 
    return ans ; 
}
 
 
int main(){
    ios::sync_with_stdio(false) ; 
    cin.tie(NULL) ; 
 
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    int x, n ; 
    cin>>x>>n ; 
    set<int> s ; 
    vector<int> a(n) ; 
    map<int,int> mp ; 
    s.insert(0) ; 
    s.insert(x) ; 
    mp[x] ++ ;
    for(int i = 0 ; i< n; i++){
        cin>>a[i] ; 
        int temp = a[i] ;  
        auto it = s.lower_bound(temp) ; 
        int r  = *it ;
        int l =*(--it) ; 

        s.insert(temp) ; 
        mp[r-l]--; 
        if(!mp[r-l])
            mp.erase(r-l) ;
        mp[r- temp]++ ; 
        mp[temp- l] ++ ; 
        cerr<<endl; 
        // cout<<(mp.end())->first <<" : " ; 
        cout<<((--mp.end())->first)<<"\n" ; 
        
        // cout<<find(s, n,x) <<" " ; 
    }
    return 0 ; 
}