#include <bits/stdc++.h>
using namespace std;

// typedef long long ll;
#define int long long

void solve(){
	int n;
	cin>>n;
	int  y, r;
	cin>>y>>r;

	int cards = y/2 + r;

	int ans = min(cards, n);
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
