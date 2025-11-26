#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// Function to generate the target k-proper string starting with a given character
string generate_t(int n, int k, char start_char) {
    string t = "";
    char current_char = start_char;
    while ((int)t.size() < n) {
        t += string(k, current_char);
        current_char = (current_char == '0') ? '1' : '0';
    }
    t = t.substr(0, n);
    return t;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        s = " " + s; // 1-based indexing

        // Generate the two possible k-proper target strings
        string t1 = generate_t(n, k, '0');
        string t2 = generate_t(n, k, '1');

        t1 = " " + t1; // 1-based indexing
        t2 = " " + t2;

        // Reverse the target strings for comparison with reversed prefixes
        string t1_rev = t1;
        reverse(t1_rev.begin() + 1, t1_rev.end());

        string t2_rev = t2;
        reverse(t2_rev.begin() + 1, t2_rev.end());

        // Arrays to store mismatches and their prefix sums
        vector<int> mis1(n + 1), pre_mis1(n + 1);
        vector<int> mis1_rev(n + 1), pre_mis1_rev(n + 1);

        vector<int> mis2(n + 1), pre_mis2(n + 1);
        vector<int> mis2_rev(n + 1), pre_mis2_rev(n + 1);

        // Compute mismatches and prefix sums for target string t1
        for (int i = 1; i <= n; ++i) {
            mis1[i] = (s[i] != t1[i]) ? 1 : 0;
            pre_mis1[i] = pre_mis1[i - 1] + mis1[i];

            mis1_rev[i] = (s[i] != t1_rev[i]) ? 1 : 0;
            pre_mis1_rev[i] = pre_mis1_rev[i - 1] + mis1_rev[i];
        }

        // Compute mismatches and prefix sums for target string t2
        for (int i = 1; i <= n; ++i) {
            mis2[i] = (s[i] != t2[i]) ? 1 : 0;
            pre_mis2[i] = pre_mis2[i - 1] + mis2[i];

            mis2_rev[i] = (s[i] != t2_rev[i]) ? 1 : 0;
            pre_mis2_rev[i] = pre_mis2_rev[i - 1] + mis2_rev[i];
        }

        int answer = -1;
        // Try both target strings
        for (int target = 1; target <= 2; ++target) {
            vector<int>& pre_mis = (target == 1) ? pre_mis1 : pre_mis2;
            vector<int>& pre_mis_rev = (target == 1) ? pre_mis1_rev : pre_mis2_rev;

            for (int p = 1; p <= n; ++p) {
                int mismatches_first = pre_mis[n] - pre_mis[p];
                int mismatches_second = pre_mis_rev[p];
                int total_mismatches = mismatches_first + mismatches_second;
                if (total_mismatches == 0) {
                    answer = p;
                    break;
                }
            }
            if (answer != -1)
                break;
        }
        cout << answer << '\n';
    }

    return 0;
}
