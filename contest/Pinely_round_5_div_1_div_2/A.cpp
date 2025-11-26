#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(){
	ll r, X, D, n;

	cin>>r>>X>>D>>n;

	string s;
	cin>>s;

	if(r<X){
		cout<<n<<endl;
		return;
	}
	ll count = ((r-X + 1) + D - 1) / D;
	
	ll val = n;
	ll ans = 0;
	for( int i = 0; i<n; i++){
		if(count==0){
			val = i;
			break;
		}
		if(s[i]=='1'){
			count--;
			ans++;
		}
	}
	ll round_after = n - val;
	ans += round_after;
	cout<<ans<<endl;

}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin>>t;
	while(t--){
		solve();
	}
}
