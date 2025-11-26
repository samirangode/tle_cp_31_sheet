#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve(){
	int n;
	cin>>n;

	vector<int> a(n);
	for(int i = 0; i<n; i++){
		cin>>a[i];	
	}
	
	int sum = accumulate(a.begin(), a.end(), 0LL);

	sort(a.rbegin(), a.rend()); // sort decreasing
	
	int rem = sum/2;
	int ans = sum - rem; // ceiling basically, so the minimum number of type 1 ops

	for(auto x : a){ // from biggest to smallest
		if(rem<=0)
			break;

		rem -= x;
		ans++;
	}
	
	cout<<ans<<endl;


}

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin>>t;
	while(t--){
		solve();	
	}

}
