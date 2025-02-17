#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    int count = 1;
    for(int i = 1;i<n; i++){
        if(s[i]!=s[i-1]){
            count+=1;
        }
    }
    if(s[0]=='0'){
        cout<<count-1<<endl;
    }
    else{
        cout<<count<<endl;
    }
    return;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}