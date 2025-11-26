#include <bits/stdc++.h>
using namespace std;

// typedef long long ll;
#define int long long

void solve(){
	int n;
	cin>>n;
	vector<int> a(n);
	for(int i = 0; i<n; i++) cin>>a[i];

	vector<int> freq(n+1);
	for(int i = 0; i<n; i++){
		freq[a[i]]++;
	}

	int ans_del = 0;
	for(int i = 0; i<=n; i++){
		if(freq[i]>i){
			ans_del+=(freq[i] - i);
		}
		else if(freq[i]<i){
			ans_del+= freq[i];
		}
	}
	cout<<ans_del<<endl;


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
