#include<bits/stdc++.h>

using namespace std;

void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    vector<int> b(n);
    for(int i = 0; i<n; i++){
        cin>>a[i];
    }
    for(int i = 0; i<n; i++){
        cin>>b[i];
    }
    unordered_set<int> ua;
    unordered_set<int> ub;
    for(int i = 0; i<n; i++){
        ua.insert(a[i]);
        ub.insert(b[i]);
    }
    bool possible = false;
    if(ua.size()>=3 || ub.size()>=3) possible = true;
    if(ua.size()==2 && ub.size()==2) possible = true;
    if(!possible){
        cout<<"NO"<<endl;
        return;
    }
    if(possible){
        cout<<"YES"<<endl;
        return;
    }
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}
