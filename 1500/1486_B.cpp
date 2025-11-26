// #include <bits/stdc++.h>
// using namespace std;

// #define int long long

// void solve(){
//     int n;
//     cin>>n;
//     vector<int> x(n);
//     vector<int> y(n);

//     for(int i = 0; i<n; i++){
//         int a, b;
//         cin>>a>>b;
//         x[i] = a;
//         y[i] = b;
//     }

//     sort(x.begin(), x.end());
//     sort(y.begin(), y.end());

//     int lower = x[(n-1)/2];
//     // int xsum = accumulate(x.begin(), x.end(),0);
//     // int ysum = accumulate(y.begin(), y.end(),0);

//     // int x1 = (xsum + n - 1)/n, x2 = xsum/n;
//     // int y1 = (ysum + n - 1)/n, y2 = ysum/n;

//     // int numx = ((x1==x2)? 1 : 2);
//     // int numy = ((y1==y2)? 1 : 2);

//     // cout<<numx*numy<<endl;

// }

// int32_t main(){
//     ios_base::sync_with_stdio(false);
//     cin.tie(nullptr);
//     int t;
//     cin>>t;
//     while(t--){
//         solve();
//     }
// }

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll count_optimal_on_line(vector<ll> v) {
    sort(v.begin(), v.end());
    int n = (int)v.size();
    // 0-indexed: lower = v[(n-1)/2], upper = v[n/2]
    ll lower = v[(n-1)/2];
    ll upper = v[n/2];
    return upper - lower + 1; // # of integer minimizers
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        vector<ll> xs(n), ys(n);
        for (int i = 0; i < n; ++i) cin >> xs[i] >> ys[i];
        ll cx = count_optimal_on_line(xs);
        ll cy = count_optimal_on_line(ys);
        cout << cx * cy << '\n';
    }
    return 0;
}
