#include <bits/stdc++.h>

using namespace std;

void solve(vector<int>& a, const int& n, const int k, int z){

    vector<int> pre_sum(n);
    pre_sum[0] = a[0];
    for(int i = 1; i<n; i++){
        pre_sum[i] = pre_sum[i-1] + a[i];
    }
    vector<int> mx_sum(n);
    int mx = 0;
    for(int i = 0; i<n; i++){
        if(i<(n-1)){
            mx = max(mx, a[i] + a[i+1]);
        }
        mx_sum[i] = mx;
    }

    int ans = 0;
    for(int t = 0; t<=z; t++){
        // number of right steps for 0 indexed = k - 2t;
        int pos = k - (2*t);
        if(pos<0){
            continue;
        }
        int only_right = pre_sum[pos];
        int left_pairs = mx_sum[pos];

        ans = max(ans, only_right + left_pairs*t);
    }

    cout<<ans<<"\n";
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin>>t;
    while(t--){

        int n,k,z;
        cin>>n>>k>>z;

        vector<int> a(n);

        for(int i = 0; i<n; i++){
            cin>>a[i];
        }

        solve(a,n,k,z);


    }
}
