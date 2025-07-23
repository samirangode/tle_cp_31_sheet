#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n;
    cin>>n;
    vector<int> b(n);
    int count = 0;
    for(int i = 0; i<n; i++){
        cin>>b[i];
        if((i!=0) && (b[i]<b[i-1])) count++;
    }
    int m = n + count;
    cout<<m<<endl;
    cout<<b[0]<<" ";
    for(int i = 1; i<n; i++){
        if(b[i]<b[i-1]){
            cout<<b[i]<<" ";
        }
        cout<<b[i]<<" ";
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