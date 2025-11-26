#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i = 0; i<n; i++){
        cin>>a[i];
    }
    int max_len = 0;
    for(int i = 0; i<n; ){
        if(a[i]==0){
            int j = i;
            int curr_len = 0;
            for(;j<n && a[j]==0; j++){
                curr_len++;
            }
            max_len = max(max_len, curr_len);
            i = j;
        }
        else{
            i++;
        }
    }
    cout<<max_len<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}
