#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    priority_queue<int> pq;

    int n, k1, k2;
    cin>>n>>k1>>k2;

    int k = k1 + k2;
    vector<int> a(n), b(n), arr(n);

    for(int i = 0; i<n; i++) cin>>a[i];
    for(int i = 0; i<n; i++){
        cin>>b[i];
        arr[i] = abs(b[i] - a[i]);
        pq.push(arr[i]);
    }

    while(k>0){
        int curr = pq.top();
        pq.pop();
        pq.push(abs(curr-1));
        k--;
    }

    int ans = 0;
    while(!pq.empty()){
        int val = pq.top();
        ans+=val*val;
        pq.pop();
    }
    cout<<ans;

}

// #include<bits/stdc++.h>
// using namespace std;

// typedef long long ll;

// priority_queue<ll> pq;

// int main(){
//     int n, k1, k2, k;
//     cin>>n>>k1>>k2;
//     k = k1+k2;
//     vector<ll> a(n), b(n), arr(n);
//     for(int i=0 ; i<n ; ++i)
//         cin>>a[i];
//     for(int i=0 ; i<n ; ++i){
//         cin>>b[i];
//         arr[i] = abs(a[i]-b[i]);
//         pq.push(arr[i]);
//     }
//     while(k>0){
//         ll curr = pq.top();
//         pq.pop();
//         pq.push(abs(curr-1));
//         k--;
//     }
//     ll ans = 0;
//     while(!pq.empty()){
//         ll curr = pq.top();
//         ans += (curr*curr);
//         pq.pop();
//     }
//     cout<<ans;
// }