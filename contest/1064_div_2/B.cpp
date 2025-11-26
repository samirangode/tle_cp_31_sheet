#include <bits/stdc++.h>
using namespace std;

// typedef long long ll;
#define int long long

void solve(){
	int a, b, n;
	cin>>a>>b>>n;

	if(b <= (a/n)){
		cout<<1<<endl;
	}
	else if(a<=b){
		cout<<1<<endl;
	}
	else{
		cout<<2<<endl;
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
