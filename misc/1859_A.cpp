#include <bits/stdc++.h>

using namespace std;


void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    unordered_set<int> us;
    for(int i = 0; i<n; i++){
        cin>>a[i];
        us.insert(a[i]);
    }
    if(us.size()==1){
        cout<<-1<<endl;
        return;
    }
    sort(a.begin(),a.end());
    // cout<<1<<" "<<a.size()-1<<endl;
    // cout<<a[0]<<endl;
    // for(int i = 1; i<n; i++){
    //     cout<<a[i]<<" ";
    // }
    vector<int> b;
    b.push_back(a[0]);
    for(int i = 1; i<n; i++){
        if(a[i]!=a[i-1]) break;
        b.push_back(a[i]);
    }
    cout<<b.size()<<" "<<n-b.size()<<endl;
    for(int i = 0; i<b.size(); i++){
        cout<<b[i]<<" ";
    }
    cout<<endl;
    for(int i = b.size(); i<n; i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}


int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}