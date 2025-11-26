#include <bits/stdc++.h>
using namespace std;

// typedef long long ll;
#define int long long

void solve(){
	int n;
	cin>>n;

	vector<int> a(n);

	for(int i = 0; i<n; i++) cin>>a[i];

	vector<int> order(n);

	iota(order.begin(), order.end(), 0);
	sort(order.begin(), order.end(), [&](int i, int j){
		return a[i] < a[j];
	});

	vector<int> L(n), R(n);
	vector<char> alive(n, 1);

	for(int i = 0; i<n; i++){
		L[i] = (i - 1 + n) % n;
		R[i] = (i+1)%n;
	}

	int ans = 0;

	int removed = 0;

	for(int idx : order){
		if(!alive[idx]) continue;

		if(removed == (n-1)) break;

		int l = L[idx];
		if(l!=idx && !alive[l]) l = L[l];

		int r = R[idx];
		if(r!=idx && !alive[r]) r = R[r];

		if(l == idx || r == idx){
			// only two elements
			int other = (l==idx ? r : l);
			if(other!=idx){
				ans += max(a[idx], a[other]);
			}
			alive[idx] = 0;
			removed++;

		}
		else{
			ans += min(a[l], a[r]);
			alive[idx] = 0;
			removed++;
			L[r] = l;
			R[l] = r;
		}

	}
	cout<< ans<<"\n";


}

int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin>>t;
	while(t--){
		solve();
	}
}
