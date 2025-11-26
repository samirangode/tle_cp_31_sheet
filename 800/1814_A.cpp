#include <bits/stdc++.h>
using namespace std;
 
void solve(){
    long long n, k;
    cin>>n>>k;
    
    
    if(!(n&1)){
        cout<<"YES"<<endl;
        return;
    }
    else{
        if(k&1){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
    
}
 
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}
