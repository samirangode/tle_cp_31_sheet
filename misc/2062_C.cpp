#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    int n;
    cin>>n;
    vector<ll> a(n);
    for(int i = 0; i<n; i++){
        cin>>a[i];
    }
    // k = 0
    ll maxSum = 0;
    ll ans = 0;
    vector<ll> prev(n);
    for(int i = 0; i<n; i++){
        prev[i] = a[i];
        ans+=a[i];
    }
    maxSum = ans;
    for(int k = 1; k<n; k++){
        ans = 0;
        for(int i = k; i<n; i++){
            a[i] = prev[i] - prev[i-1];
            ans+= a[i];
            prev[i-1] = a[i-1];
        }
        prev[n-1] = a[n-1];
        maxSum = max(maxSum, abs(ans));
    }
    cout<<maxSum<<endl;

}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve(); 
    }

}

