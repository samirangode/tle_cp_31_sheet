#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n, l, r;
    cin >> n >> l >> r;
    // Convert to 0-index. Now the target segment is from index l to r (inclusive).
    l--; r--;
    
    vector<long long> arr(n);
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }
    vector<long long > arr1 = arr;
    sort(arr1.begin()+l, arr1.end());
    long long sum1 = 0;
    for(int i = l; i<=r; i++){
        sum1+=arr1[i];
    }
    vector<long long> arr2 = arr;
    sort(arr2.begin(), arr2.begin()+r+1);
    reverse(arr2.begin(), arr2.begin()+r+1);
    long long sum2 = 0;
    for(int i = l; i<=r; i++){
        sum2+=arr2[i];
    }
    cout << min(sum1, sum2) << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}