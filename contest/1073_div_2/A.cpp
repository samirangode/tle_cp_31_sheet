#include <bits/stdc++.h>
using namespace std;

// typedef long long ll;
#define int long long

void solve(){
	int n;
	cin>>n;
	if(n<=3){
		cout<<n<<endl;
	}
	else{
		if(n&1){
			cout<<1<<endl;
		}
		else{
			cout<<0<<endl;
		}
	}
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
