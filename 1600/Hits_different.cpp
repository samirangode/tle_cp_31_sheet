#include <bits/stdc++.h>

using namespace std;

long long curr =1;
long long ans[2000007];
long long a[1500][1500] = {};

void solve(){
    int n;
    cin>>n;
    cout<<ans[n]<<"\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    for(int i = 1; i<1500; i++){
        for(int j = i-1; j>=1; j--){
            a[j][i-j] = a[j-1][i-j] + a[j][i-j-1] - 
                        a[j-1][i-j-1] + curr*curr;
            ans[curr] = a[j][i-j];
            curr++;
        }
    }
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}