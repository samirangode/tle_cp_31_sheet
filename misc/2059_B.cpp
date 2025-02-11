#include <bits/stdc++.h>
using namespace std;


void solve(){
    int n, k;
    cin>>n>>k;
    vector<int> a(n);
    for(int i = 0; i<n; i++){
        cin>>a[i];
    }

    // if k==n;
    if(k==n){
        int ans = k/2+1;
        for(int i = 0; i<n; i++){
            if(i&1){
                if(a[i]!=(i+1)/2){
                    ans = (i+1)/2;
                    break;
                }
            }
        }
        cout<<ans<<endl;
        return;
    }
    else{
        int ans = 2;
        int i = 0;
        while((n-1-i) >= (k-1)){
            if(i!=0){
                if(a[i]!=1){
                    ans = 1;
                }
            }
            
            i++;
        }
        if(a[i]!=1){
            ans = 1;
        }
        cout<<ans<<endl;
        return;
    }
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