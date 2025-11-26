#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve(){
    int n;
    cin>>n;

    vector<int> a(n);
    for(int i = 0; i<n; i++) cin>>a[i];

    int fin_xor = a[0];
    for(int i = 1; i<n; i++) fin_xor = fin_xor ^ a[i];

    if(!fin_xor){
        cout<<"YES"<<endl;
        return;
    }

    int pref_xor = 0;
    int c = 0;
    for(int i = 0; i<n; i++){
        if(pref_xor==fin_xor){
            pref_xor=0;
            c++;
        }
        pref_xor = pref_xor ^ a[i];
    }
    if(c>1){
        cout<<"YES"<<endl;
        return;
    }
    cout<<"NO"<<endl;
    
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        solve();
    }

}