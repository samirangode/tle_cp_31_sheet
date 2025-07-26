#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;  cin >> n >> m;
    vector<int> atkJ, defJ, c(m);

    for (int i = 0; i < n; ++i) {
        string pos; int s; cin >> pos >> s;
        (pos == "ATK" ? atkJ : defJ).push_back(s);
    }
    for (int &x : c) cin >> x;

    sort(atkJ.begin(), atkJ.end());
    sort(defJ.begin(), defJ.end());
    sort(c.begin(),   c.end());

    int na = atkJ.size(), nd = defJ.size();
    ll ans = 0;

    // -------- Case 1: only attack ATK cards (not killing all) --------
    {
        ll sum = 0;
        int i = m - 1, j = 0;          // largest Ciel, smallest ATK
        while (i >= 0 && j < na) {
            if (c[i] >= atkJ[j]) {
                sum += c[i] - atkJ[j];
                --i; ++j;
            } else {
                --i;                   // this Ciel card is too weak; skip it
            }
        }
        ans = max(ans, sum);
    }

    // -------- Case 2: kill ALL Jiro cards, then direct --------
    if (m >= na + nd) {
        multiset<int> ms(c.begin(), c.end());

        // 1) remove cards to kill all DEF (> rule)
        bool ok = true;
        for (int d : defJ) {
            auto it = ms.upper_bound(d);
            if (it == ms.end()) { ok = false; break; }
            ms.erase(it);
        }

        if (ok) {
            // Put remaining cards into a vector (sorted)
            vector<int> rem(ms.begin(), ms.end());
            ll sumRem = 0;
            for (int x : rem) sumRem += x;

            // 2) Feasibility check for killing all ATKs with >= rule
            int p = 0;                     // pointer in rem
            for (int a : atkJ) {
                while (p < (int)rem.size() && rem[p] < a) ++p;
                if (p == (int)rem.size()) { ok = false; break; }
                ++p; // use this card
            }

            if (ok) {
                ll sumAtk = 0;
                for (int a : atkJ) sumAtk += a;
                ll damage = sumRem - sumAtk;   // formula explained above
                ans = max(ans, damage);
            }
        }
    }

    cout << ans << '\n';
    return 0;
}

