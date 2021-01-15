/*
Question - Time required to make t products with n machines which make a given product after certain interval of time
Solved - O(nlog(10^18)) Time Complexity, applying binary search on the time. 
Approach-set upper bound as 1e18 because the worst case will be no. of req items=1e9 and no. of machines=1 so max.answer will not be more than 1e18.
*/
#include<bits/stdc++.h>

using namespace std; 

#define ll long long int 

int main(){
    int n , t;  
    cin>> n >> t; 

    vector<int> a(n) ; 
    for(int i = 0 ; i<n  ;i++)
        cin>>a[i] ; 

    ll k= 0 ; // starting with 0 time ; 
    ll l = 0 , r= 1e18 ; 

    while (l+1< r) {
        ll mid = (r-l)/2 + l; 
        ll count = 0 ; 
        bool flag = false ; 
        for(int i = 0; i<n ; i++){
            count += mid / a[i] ; 
            if(count >=t){
                flag = true ; 
            }
        }
        if(flag){
            r = mid  ; 

        }else
            l = mid; 

    }

    cout<<r<<"\n" ; 
    return 0 ; 
}

