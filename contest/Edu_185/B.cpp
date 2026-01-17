#include <bits/stdc++.h>
using namespace std;

// typedef long long ll;
#define int long long

void solve(){
	int n;
	cin>>n;
	vector<int> b(n);
	for(int i = 0; i<n; i++) cin>>b[i];

	sort(b.begin(), b.end());

	int sum = 0;
	for(int i = 0; i<n; i++) sum+=b[i];

	int zero_ind = upper_bound(b.begin(), b.end(), 0) - b.begin();

	if(zero_ind==n) zero_ind = 0;

	// l has to be greater than zero_ind
	// after the first operation it should also have enough sum for n-1 ops

	int best_pos_l = 2*n - sum;

	best_pos_l = max(best_pos_l, zero_ind+1);

	cout<<n - best_pos_l + 1<<endl;

	// l should be greater than 0 and zero_ind


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
