#include <bits/stdc++.h>
using namespace std;

// typedef long long ll;
#define int long long

void solve(){
	int n;
	cin>>n;
	vector<int> a(n);
	int maxi = LLONG_MIN;
	for(int i = 0; i<n; i++){
		cin>>a[i];
		maxi = max(maxi, a[i]);
	}
	cout<<maxi*n<<endl;

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
