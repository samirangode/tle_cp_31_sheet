#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    vector<vector<int>> a(n, vector<int>(n));
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            cin >> a[i][j];
        }
    }
    priority_queue<int,vector<int>, greater<int>> pq;
    bool found_zero = false;

    for(int i = 0; i<n; i++){
        int count = 0;
        for(int j = n-1; j>=0; j--){
            if(j==(n-1)){
                if(a[i][j]!=1){
                    if(!found_zero) {found_zero = true; pq.push(0); break;}
                    else break;
                }
            }
            if(a[i][j]==1) count++;
            else break;
        }
        if(count!=0) pq.push(count);
    }
    int mex = -1;
    while(!pq.empty()){
        pq.pop();
        mex++;
    }

    // if(!found_zero){
    //     cout<<0<<endl;
    //     return;
    // }
    cout<<mex+1<<endl;


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
