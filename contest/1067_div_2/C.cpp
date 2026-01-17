#include <bits/stdc++.h>
using namespace std;

// typedef long long ll;
#define int long long

void solve(){
	int n, k;
	cin>>n>>k;

	vector<int> a(n+1);
	for(int i = 1; i<=n; i++) cin>>a[i];
	vector<int> b(n+1);
	for(int i = 1; i<=n; i++) cin>>b[i];

	vector<int> L(n+1), R(n+2);

	L[1] = a[1];
	int base = L[1];

	for(int i = 2; i<=n; i++){
		L[i] = max(L[i-1] + a[i], a[i]);
		base = max(base, L[i]);
	}

	// backward
	R[n] = a[n];
	for(int i = n-1; i>=1; i--){
		R[i] = max(a[i], R[i+1] + a[i]);
	}

	int ans = base;

	if(k&1){
		for(int i = 1; i<=n; i++){
			int left = (i>1 ? max(0ll, L[i-1]) : 0ll);
			int right = (i<n ? max(0ll, R[i+1]) : 0ll);
			ans = max(left + a[i] + right + b[i], ans);
		}
	}

	cout<<ans<<endl;

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
