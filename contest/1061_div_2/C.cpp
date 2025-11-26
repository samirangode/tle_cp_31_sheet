#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n, k;
	cin>>n>>k;

	vector<int> freq(n+1,0);

	vector<int> prefix(n+1,0); 
	for(int i = 0; i<n; i++){
		int a;
		cin>>a;
		freq[a]++;
	}
	for(int i = 1; i<=n; i++){
		prefix[i] = prefix[i-1] + freq[i];
	}

	int ans = 1;
	for(int g = 2; g<=n; g++){
		int t = min(n, 4*g-1);
		int good = n - prefix[t];	

		if(g<=n) good += freq[g];
		if(2*g<=n) good += freq[2*g];
		if(3*g<=n) good += freq[3*g];

		if(good>=n-k) ans = g;
	}

	cout<<ans<<endl;
}
int main(){
ios::sync_with_stdio(false);
cin.tie(nullptr);

int t;
cin>>t;
while(t--){
	solve();

}
}
