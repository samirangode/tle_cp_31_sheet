#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    vector<string> perms = {"abc", "acb", "bac", "bca", "cab", "cba"};
    vector<vector<int>> cost(6, vector<int>(n+1, 0));

    // Generate cost arrays for each permutation pattern
    for (int p = 0; p < 6; ++p) {
        for (int i = 0; i < n; ++i) {
            if (s[i] != perms[p][i % 3]) {
                cost[p][i+1] = cost[p][i] + 1;
            } else {
                cost[p][i+1] = cost[p][i];
            }
        }
    }

    // Process each query
    for (int i = 0; i < m; ++i) {
        int l, r;
        cin >> l >> r;
        int min_cost = n; // Initialize with the maximum possible cost
        for (int p = 0; p < 6; ++p) {
            min_cost = min(min_cost, cost[p][r] - cost[p][l-1]);
        }
        cout << min_cost << endl;
    }

    return 0;
}

