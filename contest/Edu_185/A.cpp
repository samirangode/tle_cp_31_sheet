#include <bits/stdc++.h>
using namespace std;

// typedef long long ll;
#define int long long

void solve(){
	int n;
	cin>>n;
	vector<int> an = {0, 1, 9, 29, 56};
	if(n<=4){
		cout<<an[n]<<endl;
		return;
	}

	int ans = 5*n*n - 5*n - 5; 
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
