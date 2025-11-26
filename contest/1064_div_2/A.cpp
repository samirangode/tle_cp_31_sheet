#include <bits/stdc++.h>
using namespace std;

// typedef long long ll;
#define int long long

void solve(){
	int n;
	cin>>n;
	string s;
	cin>>s;

	
	int count = 0;
	for(int i = n-2; i>=0; i--){
		if(s[i]!=s[n-1]){
			count++;
		}
	}
	cout<<count<<endl;


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
