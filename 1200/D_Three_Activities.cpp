#include <bits/stdc++.h>

using namespace std;

int f(int i, int chosen, vector<int>& a, 
      vector<int>& b, vector<int>& c,
      vector<vector<int>>& dp){
    if(i==a.size()) return 0;

    if(dp[i][chosen]!=-1)
        return dp[i][chosen];

    int tf1=0, tf2 =0, tf3 =0;
    if((chosen & (1<<2))==0)
        tf1 = a[i] + f(i+1, chosen | 1<<2, a, b, c,dp);
    if((chosen & (1<<1))==0)
        tf2 = b[i] + f(i+1, chosen | 1<<1, a, b, c,dp);
    if((chosen & (1))==0)
        tf3 = c[i] + f(i+1, chosen | 1, a, b, c,dp);

    int tf4 = f(i+1, chosen, a, b, c,dp);

    return dp[i][chosen] = max(max(tf1,tf2), max(tf3, tf4));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; // Number of test cases
    cin >> t;
    while (t--) {
        int n; // Number of days of winter holidays
        cin >> n;

        vector<int> skiing(n), movie(n), boardgames(n);

        // Read skiing friends
        for (int i = 0; i < n; ++i) {
            cin >> skiing[i];
        }

        // Read movie friends
        for (int i = 0; i < n; ++i) {
            cin >> movie[i];
        }

        // Read board games friends
        for (int i = 0; i < n; ++i) {
            cin >> boardgames[i];
        }

        // Initialize maximum friends variable
        int max_friends = 0;

        // Implement the logic to find the maximum number of friends that can join Monocarp
        // on three distinct days, with different activities each day.
        // This will likely involve some form of looping through the three vectors.
        // A possible naive approach is to iterate over three distinct days and calculate the max sum.
        // for (int i = 0; i < n; ++i) {
        //     for (int j = i + 1; j < n; ++j) {
        //         for (int k = j + 1; k < n; ++k) {
        //             int current_max = skiing[i] + movie[j] + boardgames[k];
        //             max_friends = max(max_friends, current_max);
        //         }
        //     }
        // }
        vector<vector<int>> dp(skiing.size()+1,vector<int>(9,-1));
        max_friends = f(0,0,skiing,movie,boardgames,dp);

        // Print the result for the current test case
        cout << max_friends << "\n";
    }
    return 0;
}
