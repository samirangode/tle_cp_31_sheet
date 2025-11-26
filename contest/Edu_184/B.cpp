#include <bits/stdc++.h>
using namespace std;

// typedef long long ll;
#define int long long

void solve(){
	string s;
	cin>>s;

	int n = s.size();
	if(n==1){
		cout<<1<<endl;
		return;
	}

	bool infp = false;
	for(int i = 0; i<(n-1); i++){
		if(s[i]=='>'){
			if(s[i+1]=='<' || s[i+1]=='*'){
				infp=true;
				break;
			}
		}
		else if(s[i]=='*'){
			if(s[i+1]=='<' || s[i+1]=='*'){
				infp=true;
				break;
			}
		}
	}

	if(infp){
		cout<<-1<<endl;
		return;
	}
	int lcs = 0;
	int rcs = 0;
	for(int i = 0; i<n; i++){
		if(s[i]=='*' || (s[i]=='>')){
			lcs = n - i;
			break;
		}
	}
	for(int i = n-1; i>=0; i--){
		if(s[i]=='*' || (s[i]=='<')){
			rcs = i+1;
			break;
		}
	}
	
	int val = max(lcs, rcs);
	cout<<val<<endl;


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
