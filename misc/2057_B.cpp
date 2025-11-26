#include <bits/stdc++.h>
 
using namespace std;
 
void solve(){
    int n, k;
    cin>>n>>k;
    vector<int> a(n);
    // unordered_map<int,int> um;
    for(int i = 0; i<n; i++){
        cin>>a[i];
        // um[a[i]]++;
    }
    vector<int> distinct = {1};
    // for(auto it : um){
    //     distinct.push_back(it.second);
    // }
    sort(a.begin(), a.end());
    for(int i = 1; i<n; i++){
        if(a[i]==a[i-1]){
            distinct.back()++;
        }
        else{
            distinct.emplace_back(1);
        }
    }
    
    sort(distinct.begin(), distinct.end());
    int m = distinct.size();
    for(int i = 0; i<m; i++){
        if(distinct[i]>k){
            cout<<m-i<<endl;
            return;
        }
        k-=distinct[i];
    }
    cout<<1<<endl;
    return;
}
 
int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}
