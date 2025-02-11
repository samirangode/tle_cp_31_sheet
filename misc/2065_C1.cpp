#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve(){
    int n, m;
    cin>>n>>m;
    vector<ll> a(n);
    vector<ll> b(m);
    for(int i = 0; i<n; i++){
        cin>>a[i];
    }
    for(int i = 0; i<m; i++){
        cin>>b[i];
    }
    bool ans = true;
    for(int i = n-1; i>=0; i--){
        // maximize for each element
        if(i==(n-1)){
            a[i] = max(a[i], b[0]-a[i]);
        }
        else if(i<(n-1)){
            if(a[i]>a[i+1]){
                a[i] = b[0] - a[i];
            }
            else{
                ll max_possible = max(a[i], b[0]-a[i]);
                if(max_possible<=a[i+1]){
                    a[i] = max_possible;
                }
            }
            if(a[i]>a[i+1]){
                ans = false;
                break;
            }
        }
    }
    if(ans){
        cout<<"YES"<<endl;
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
