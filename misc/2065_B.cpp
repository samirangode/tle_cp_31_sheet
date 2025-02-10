#include <bits/stdc++.h>

using namespace std;


void solve(){
    string s;
    cin>>s;
    if(s.length()==1){
        cout<<1<<endl;
        return;
    }
    int n = s.size();
    int ans = n;
    for(int i = 0; i<(n-1); i++){
        if(s[i]==s[i+1]){
            ans = 1;
            break;
        }
    }
    cout<<ans<<endl;
    // cout<<s.substr(0,s.length()-2)<<"i"<<endl;
    // return;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}
