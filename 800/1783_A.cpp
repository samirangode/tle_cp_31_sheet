#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    map<int,int> m;
    for(int i = 0; i<n; i++){
        cin>>a[i];
        m[a[i]]++;
    }
    vector<int> ans;
    for(auto it=m.rbegin(); it!=m.rend();it++){
        ans.push_back(it->first);
    }
    for(auto it=m.rbegin(); it!=m.rend();it++){
        int val = it->second;
        val--;
        // cout<<val<<endl;
        while(val--){
            ans.push_back(it->first);
        }
    }
    if(ans[0]==ans[1]){
        cout<<"NO"<<endl;
    }
    else{
        cout<<"YES"<<endl;
        for(int i = 0; i<n; i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }
    
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}
