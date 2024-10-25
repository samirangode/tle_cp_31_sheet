#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll solve(vector<ll>& arr, ll n, ll k){
    if(k>2) return 0;

    sort(arr.begin(),arr.end());

    ll min1 = arr[0], min2 = arr[0];

    for(int i = 1; i<n; i++){
        ll diff = arr[i] - arr[i-1];
        min1 = min(abs(diff), min1);
    }
    if(k==1){
        return min1;
    }
    for(int i = 0; i<n; i++){
        for(int j = 0; j<i; j++){
            ll diff = arr[i] - arr[j];
            int ind = lower_bound(arr.begin(), arr.end(), diff) - arr.begin();
            if(ind == n){
                min2 = min(abs(diff - arr[n-1]),min2);
            }
            else{
                min2 = min(abs(diff-arr[ind]), min2);
                if(ind>0){
                    min2 = min(abs(diff-arr[ind-1]), min2);
                }
            }
        }
    }
    return min(min1, min2);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    ll t;
    cin>>t;
    while(t--){
        ll n, k;
        cin>>n;
        cin>>k;
        vector<ll> arr(n);
        for(int i=0; i<n; i++){
            cin>>arr[i];
        }
        ll ans = solve(arr,n,k);

        cout<<ans<<"\n";
    }
}
