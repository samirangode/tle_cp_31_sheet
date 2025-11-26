#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n, k;
    cin>>n>>k;
    vector<int> a(n);

    bool occurs = false;
    for(int i = 0; i<n; i++){
        cin>>a[i];
        if(a[i]==k) occurs = true;
    }

    if(occurs) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}
