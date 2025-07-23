#include <bits/stdc++.h>

using namespace std;

void solve(){
    int x, k;
    cin>>x>>k;
    int ans = -1;
    if(x%k!=0){
        ans =1;
        cout<<ans<<endl;
        cout<<x<<endl;
        return;
    }
    else{
        ans = 2;
        cout<<ans<<endl;
        cout<<x+1<<" "<<-1<<endl;
    }
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}
