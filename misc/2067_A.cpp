#include <bits/stdc++.h>
using namespace std;
 
void solve(){
    int x, y;
    cin>>x>>y;
    
    int val = (y - x - 1)%(-9);
    int div = (y - x - 1)/(-9);
    if(val==0 && div>=0){
        cout<<"YES"<<endl;
        return;
    }
    else{
        cout<<"NO"<<endl;
    }
}
 
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}
