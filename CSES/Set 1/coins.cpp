#include<bits/stdc++.h>
using namespace std ; 
#define ll long long int 

int main(){ 
    string s; 
    cin>>s ; 
    sort(s.begin() , s.end()) ; 
    ll i = 0 ; 
    int a[26] = {0} ; 
    for(char x : s){
        a[x - 'A'] ++ ; 
    }
    int check = 0 ; 
    for(int i = 0 ;i < 26 ;i++){
        check += a[i] & 1 ; 
    }

    if(check > 1 || (check == 1 && s.size() % 2 == 0))
    {
        cout<<"NO SOLUTION\n" ; 
        return 0 ; 
    }

    string t ; 
    for(int i = 0 ; i < 26 ; i++){
        if(a[i] % 2 == 0 && a[i] > 0  ){
            for(int j = 0 ; j< a[i] /2; j++){
                cout<< char('A' + i) ; 
            }
        }
    }

    for(int i = 0 ; i < 26 ; i++){
        if(a[i] & 1){
             for(int j = 0 ; j< a[i] ; j++){
                cout<<char('A' + i) ; 
            }
        }
    }

    for(int i = 25 ; i >-1 ; i--){
        if(a[i] % 2 == 0 && a[i] > 0 ){
            for(int j = a[i] / 2  ; j< a[i] ; j++){
                cout<<char('A' + i) ; 
            }
        }
    }
    // cout<<t <<endl ;
    return 0 ; 
}