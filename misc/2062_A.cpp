#include <bits/stdc++.h>
using namespace std;


void solve(){
    string s;
    cin>>s;
    int n = s.length();
    int ans = 0;
    for(int i = 0; i<n ;i++){
        if(s[i]=='1') ans++;
    }
    cout<<ans<<endl;
}



int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}