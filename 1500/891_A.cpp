// if all of them have a common factor, that is gcd is not 1 -> -1
// If 2 3 4 5 6 7 8 of size n -> n
// If I can find a single pair with gcd 1 all can be made 1 in n operations.
// not possible to do it in less than n operations. So ops>=n or -1
// Find all gcds and then gcds of gcds and so on. If that is not 1 -> -1
// Otherwise 

// 2 4 8 6 6 9

#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n;
    cin>>n;

    vector<int> a(n);
    for (auto &i : a) cin >> i; // read array a of size n

    int g = a[0];

    int cnt = 0;
    for (auto i : a) {
				g = __gcd(g, i); // gcd of the entire array
				if (i == 1) cnt++;
		}

		if (g > 1) { // if overall gcd > 1, it's impossible to reach all 1's
				cout << "-1\n";
				return;
		}

		if (cnt) { // if there is at least one 1
				// Use the existing 1 as a seed to spread: each non-1 becomes 1 in one operation
				cout << n - cnt << '\n';
				return;
		}

		int ans = 2 * n; // large initial value (upper bound placeholder)
		// Find the shortest subarray with gcd == 1. If subarray [i..j] has gcd 1,
		// it takes (j - i) operations to make a 1 inside, then (n - 1) to spread it across the array.
		for (int i = 0; i < n; i++) {
				int gc = a[i];
				for (int j = i + 1; j < n; j++) {
						gc = __gcd(gc, a[j]); // progressive gcd of a[i..j]
						if (gc == 1) { // found minimal j for this i
								ans = min(ans, (n - 1) + (j - i));
								break; // no need to extend further for this i
						}
				}
		}

		cout << ans << '\n';
}
int32_t main() {
		ios::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);

        solve();
}