#include <bits/stdc++.h>
using namespace std;

#define int long long


void solve(){
	int n;
	cin>>n;
	vector<int> a(n+1,0);
	for(int i = 1; i<=n; i++){
		cin>>a[i];
	}
	vector<int> b(n+1,0);
	for(int i = 1; i<=n; i++){
		cin>>b[i];
	}

	vector<int> pr(n+1,0);
	for(int i = 1; i<=n; i++){
		pr[i] = pr[i-1] + b[i];
	}

	vector<int> cnt(n+2,0), ans(n+1,0);
	for(int i = 1; i<=n; i++){
		int x = a[i] + pr[i-1];
		auto j = upper_bound(pr.begin(), pr.end(), x) - pr.begin();

		if(j<=n){
			ans[j] += x - pr[j-1]; //partial tea which person j drinks
		}
		cnt[i]++;// every person from here onwards had a[i] till their limit
		cnt[j]--;// till here
	}
	// prefix to find how many times each person had their full share
	for(int i = 1; i<= n; i++){
		cnt[i] += cnt[i-1];
		ans[i] += cnt[i] * b[i];
	}
	for(int i = 1; i<=n; i++){
		cout<<ans[i]<<" ";
	}
	cout<<endl;
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
