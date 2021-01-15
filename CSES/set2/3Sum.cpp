#include<bits/stdc++.h>

using namespace std; 

#define ll long long int 

int main(){

    int n ; 
    ll t ; 
    cin>>n >> t; 

    vector<vector<int>> a ; 
    for(int i = 0 ; i< n ;i++){
        int temp ; 
        cin>>temp ;
        a.push_back({temp, i+1 }) ;
    }
    sort(a.begin(), a.end()) ; 

    for(int i = 0 ;i <n ;i++){
        int l= i+1 , r = n-1 ; 
        while(l< r){
            int sum = a[i][0] + a[l][0] + a[r][0] ; 

            if(sum > t){
                r-- ; 
            }else if(sum < t){
                l++ ; 
            }
            else{
                cout<<a[i][1]<<" "<<a[l][1] <<" " <<a[r][1]<<endl; 
                return 0 ; 
            }
        }
    }
    cout<<"IMPOSSIBLE\n" ; 
}