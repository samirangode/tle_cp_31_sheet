#include <bits/stdc++.h>
using namespace std;
 
void solve(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    for(int i = 0; i<(n/2); i++){
        if(!((s[i]-'0')^(s[n-1-i]-'0'))){
            cout<<n-2*(i)<<endl;
            return;
        }
    }
    if(n&1){
        cout<<1<<endl;
    }
    else{
        cout<<0<<endl;
    }
   
}
 
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}
