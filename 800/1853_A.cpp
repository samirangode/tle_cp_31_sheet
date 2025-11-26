#include <bits/stdc++.h>

using namespace std;


void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i = 0; i<n; i++){
        cin>>a[i];
    }
    int min_diff = INT_MAX;
    for(int i = 0; i<(n-1); i++){
        int diff = a[i+1] - a[i];
        min_diff = min(min_diff, diff);
    }
    if(min_diff < 0 ){
        cout<<"0"<<endl;
        return;
    }
    cout<<(min_diff+2)/2<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}
