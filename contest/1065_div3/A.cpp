#include <bits/stdc++.h>
using namespace std;

// typedef long long ll;
#define int long long

void solve(){
	int n;
	cin>>n;
	if(n&1){
		cout<<0<<endl;
		return;
	}
	int all_chickens = n/2;
	int cnt  = 1;
	for(int i = 0; i<all_chickens; i++){
		if((n - (i)*2)%4) continue;
		cnt++;
	}
	cout<<cnt<<endl;


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
