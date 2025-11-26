#include <bits/stdc++.h>
using namespace std;

typedef long long ll;


void solve(){
	int n;
	cin>>n;

	vector<int> a(n);
	for(int i = 0; i<n; i++){
		cin>>a[i];	
	}
	vector<int> dp(n+1, n);

	dp[n] = 0;
	for(int i = n-1; i>=0; i--){
		int choose = n, unchoose=n;

		if(i+a[i]+1<(n+1)){
			choose = dp[i+a[i]+1];
		}
		unchoose = 1 + dp[i+1];

		dp[i] = min(choose, unchoose);
	}

	cout<<dp[0]<<endl;
	
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin>>t;
	while(t--){
		solve();	
	}

}
