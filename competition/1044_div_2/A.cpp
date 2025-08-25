#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve(){
    int n;
    cin>>n;
    unordered_set<int> s;
    bool possible = false;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        if(s.find(x) != s.end()){
            possible = true;
        }
        s.insert(x);
    }
    if(possible) cout<<"YES\n";
    else cout<<"NO\n";
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
