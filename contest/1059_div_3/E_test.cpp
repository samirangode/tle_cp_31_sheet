#include <bits/stdc++.h>
using namespace std;

// We maintain a min-heap by (frequency, value).
// On each step, we pop until we find a value != last and != second_last.
// We temporarily hold popped disallowed values, pick the first allowed one,
// then put the held values back, and finally reinsert the chosen value
// with incremented frequency.

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];

        // frequency of values in [1..n]
        vector<int> freq(n + 1, 0);
        for (int v : a) ++freq[v];

        // min-heap by (freq, value)
        using P = pair<int,int>;
        priority_queue<P, vector<P>, greater<P>> pq;
        for (int v = 1; v <= n; ++v) pq.push({freq[v], v});

        // track the last two values of the current array tail
        int last  = a[n - 1];
        int last2 = a[n - 2];   // n >= 3 per problem

        vector<int> ans;
        ans.reserve(k);

        for (int step = 0; step < k; ++step) {
            vector<P> hold;  hold.reserve(2); // at most two disallowed values
            P pick{-1, -1};

            // Find smallest-frequency value not equal to last or last2
            while (!pq.empty()) {
                auto cur = pq.top(); pq.pop();
                int f = cur.first, v = cur.second;
                if (v != last && v != last2) {
                    pick = cur;
                    break;
                } else {
                    hold.push_back(cur);
                }
            }

            // Put the disallowed ones back
            for (auto &e : hold) pq.push(e);

            // We must always find a pick because n >= 3 ⇒ there exists a valid v
            // (If being ultra-defensive, you could assert here.)
            int v = pick.second;
            int f = pick.first;

            ans.push_back(v);

            // Update frequencies and heap
            ++f;
            pq.push({f, v});

            // Slide the window of last two
            last2 = last;
            last  = v;
        }

        // Output the k appended values
        for (int i = 0; i < k; ++i) {
            if (i) cout << ' ';
            cout << ans[i];
        }
        cout << '\n';
    }
    return 0;
}

