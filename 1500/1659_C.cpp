#include <bits/stdc++.h>
using namespace std;

#define int long long


void solve(){
	int n,a,b ;
	cin>>n>>a>>b;

	vector<int> x(n+1);

	for(int i = 1;i<=n; i++){
		cin>>x[i];
	}

	vector<int> suffix(n+2,0);
	for(int i = n; i>=0; i--){
		suffix[i] = suffix[i+1] + x[i];
	}

	int ans = INT64_MAX;
	for(int i = 0; i<=n; i++){
		int val = x[i] * (a+b) + (suffix[i+1] - (n-i)*x[i])*b;
		ans = min(ans,val);
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
