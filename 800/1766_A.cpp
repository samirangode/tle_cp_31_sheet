#include <bits/stdc++.h>
 
using namespace std;
 
 
void solve(){
    int n;
    cin>>n;
    string s = to_string(n);
    int ans = 0;
    ans += s[0]-'0';
    ans += int(s.length() - 1)*9;
    cout<<ans<<endl;
}
 
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    
}
