#include <bits/stdc++.h>
using namespace std;

// typedef long long ll;
#define int long long

void solve(){
	int n, k, Q;
	cin>>n>>k>>Q;
	
	vector<vector<int>> c1;
	vector<vector<int>> c2;

	int c, l, r;
	for(int i = 0; i<Q; i++){
		cin>>c>>l>>r;	
		if(c==1) c1.push_back({l,r});
		if(c==2) c2.push_back({l,r});
	}
	
	vector<int> a(n+1);

	vector<int> pre_a(n+1);
	for(int i = 0; i<c1.size(); i++){
		pre_a[c1[i][0]]++;
		pre_a[c1[i][1]]--;
	}
	for(int i = 1; i<=n; i++) pre_a[i]+=pre_a[i-1];

	for(int i = 1; i<=n; i++){
		if(pre_a[i]>=1) a[i] = k;
	}

	sort(c2.begin(), c2.end());

	int j = 0, r = k;
	for(int q = 0; q<Q; q++){
		vector<int> check(k);

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
