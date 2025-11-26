// #include <bits/stdc++.h>

// using namespace std;


// void min_ops(vector<int>& dp){
//     dp[0] = 0; dp[1] = 0; 
//     int n = dp.size();
//     // for(int k = 2; k<n; k++){
//     //     int min_num =INT_MAX;
//     //     for(int i = 1; i<k; i++){
//     //         if((k-i)%i == 0){
//     //             int num_ops = dp[k-i] + 1;
//     //             min_num = min(num_ops, min_num);
//     //         }
//     //     }
//     //     dp[k] = min_num;
//     // }

//     for(int k = 2; k<n; k++){
//         // int min_num = INT_MAX;
//         for(int x = 1; x<=k; x++){
//             int j = k + k/x;
//             if(j<n) dp[j] = min(dp[j], dp[k] + 1);
//         }
//     }


//     // d[1] = 0;
//     // int N = d.size();
//     // for (int i = 1; i < N; ++i) {
//     //     for (int x = 1; x <= i; ++x) {
//     //     int j = i + i / x;
//     //     if (j < N) d[j] = min(d[j], d[i] + 1);
//     //     }
//     // }
// }

// void solve(vector<int>& b, vector<int>& c, 
//             const vector<int>& dp, const int& n, const int& k){
//     // dp[i] min number of operations needed to get i from 1

//     // vector<pair<int, int>> coins_ops(n);;
//     // for(int i = 0; i<n; i++){
//     //     coins_ops[i].first = c[i];
//     //     coins_ops[i].second = dp[b[i]];
//     // }
//     // // sort(coins_ops.begin(), coins_ops.end(), [&](pair<int, int> a, pair<int, int> b){
//     // //     float(float(a.first)/(float(a.second) +  ))
//     // // });
//     // int sum = 0;
//     // for(int x : b) sum+= dp[x];
//     // int new_k = min(k,sum);

//     // vector<vector<int>> ks_dp(n+1, vector<int>(new_k+1,0));
    
//     // for(int i = n-1; i>=0; i--){
//     //     for(int j = new_k; j>=0; j--){
//     //         int choose = 0;
//     //         if(j>=dp[b[i]]){
//     //             choose = ks_dp[i+1][j-dp[b[i]]] + c[i];
//     //         }
//     //         int no_choose = ks_dp[i+1][j];

//     //         ks_dp[i][j] = max(ks_dp[i][j], max(choose, no_choose));
//     //     }
//     // }

//     // cout<<*max_element(ks_dp[0].begin(), ks_dp[0].end())<<endl;

//     int sum = 0;
//     for (int x : b) sum += dp[x];
//     int new_k = min(k, sum);
//     vector<int> ks_dp(k + 1, 0);
//     for (int i = 0; i < n; ++i) {
//       for (int j = new_k - dp[b[i]]; j >= 0; j--) {
//         ks_dp[j + dp[b[i]]] = max(ks_dp[j + dp[b[i]]], ks_dp[j] + c[i]);
//       }
//     }
//     cout << *max_element(ks_dp.begin(), ks_dp.end()) << '\n';

// }

// int main(){
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);

//     int t;
//     cin>>t;
//     vector<int> dp(1001);
//     min_ops(dp);
//     while(t--){

//         int n, k;
//         cin>>n; cin>>k;
//         vector<int> b(n);
//         for (int i = 0; i < n; i++)
//         {
//             cin>>b[i];
//         }
//         vector<int> c(n);
//         for (int i = 0; i < n; i++)
//         {
//             cin>>c[i];
//         }

//         solve(b,c,dp,n,k);
        
        

//     }

// }

#include <bits/stdc++.h>

using namespace std;

const int N = 1001;

int main() {
  vector<int> d(N, N);
  d[1] = 0;
  for (int i = 1; i < N; ++i) {
    for (int x = 1; x <= i; ++x) {
      int j = i + i / x;
      if (j < N) d[j] = min(d[j], d[i] + 1);
    }
  }
  
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    vector<int> b(n), c(n);
    for (int &x : b) cin >> x;
    for (int &x : c) cin >> x;
    int sum = 0;
    for (int x : b) sum += d[x];
    k = min(k, sum);
    vector<int> dp(k + 1, 0);
    for (int i = 0; i < n; ++i) {
      for (int j = k - d[b[i]]; j >= 0; j--) {
        dp[j + d[b[i]]] = max(dp[j + d[b[i]]], dp[j] + c[i]);
      }
    }
    cout << *max_element(dp.begin(), dp.end()) << '\n';
  }
}
