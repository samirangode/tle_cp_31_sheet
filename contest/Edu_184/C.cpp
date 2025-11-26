#include <bits/stdc++.h>
using namespace std;

// typedef long long ll;
#define int long long

void solve(){
	int n, a;
	cin>>n>>a;

	vector<int> v(n);
	for(int i = 0; i<n; i++) cin>>v[i];

	// if b > a
	int b = a+1;
	int numg = 0;
	for(int vi : v){
		numg += ((abs(b-vi)<abs(a-vi))? 1:0 );
	}
	int numl = 0;
	int bl = a-1;
	for(int vi : v){
		numl += ((abs(bl-vi)<abs(a-vi))? 1:0 );
	}

	if(numg>numl){
		cout<<b<<endl;
	}
	else{
		cout<<bl<<endl;
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
