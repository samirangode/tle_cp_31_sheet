#include <bits/stdc++.h>

using namespace std;

void solve(){
    vector<int> a(5);
    for(int i = 0; i<5; i++){
        if(i==2) continue;
        cin>>a[i];
    }
    unordered_set<int> us;
    // for i = 0
    int val_0 = a[0] + a[1];
    us.insert(val_0);
    // for i = 1
    int val_1 = a[3] - a[1];
    us.insert(val_1);
    // for i = 2
    int val_2 = a[4] - a[3];
    us.insert(val_2);

    cout<<3 - us.size() + 1<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}
