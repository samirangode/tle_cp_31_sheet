#include <bits/stdc++.h>
using namespace std;


void solve(){
	int n;
	cin>>n;
	vector<int> a(n+1,0);
	string s;
	for(int i = 0; i<n; i++){
		cin>>a[i+1];
	}
	cin>>s;
	vector<int> pre(n+1,0);
	int xor1 = 0, xor0 = 0;
	for(int i = 0; i<n; i++){
		if(s[i]=='1'){
			xor1 = xor1 ^ a[i+1];
		}
		else if(s[i]=='0'){
			xor0 = xor0 ^ a[i+1];
		}
	}
	for(int i = 1; i<=n; i++){
		pre[i] = pre[i-1] ^ a[i];
	}
	int Q;
	cin>>Q;
	int tp = 0;
	for(int q = 0; q<Q; q++){
		cin>>tp;
		if(tp==1){
			int l, r;
			cin>>l>>r;
			int xorlr = pre[r] ^ pre[l-1];
			xor0 = xor0 ^ xorlr;
			xor1 = xor1 ^ xorlr;

		}
		else if(tp==2){
			int g;
			cin>>g;
			int val = ((g==1) ? xor1 : xor0);
			cout<<val<<" ";
		}
	}
	cout<<endl;
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
