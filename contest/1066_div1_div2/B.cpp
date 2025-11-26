#include <bits/stdc++.h>
using namespace std;

// typedef long long ll;
#define int long long

void solve(){
	int n, x, y;
	cin>>n>>x>>y;
	string s;
	cin>>s;
	// int n = s.size();
	x = abs(x); y = abs(y);
	for(int i = n-1; i>=0; i--){
		if(x==0 && y ==0 ) break;

		if(s[i]=='4'){
			if(x>y && x>0) x--;
			else if(y>=x && y>0) y--; 
		}
		else if(s[i]=='8'){
			if(x>0) x--;
			if(y>0) y--;
		}
	}
	if(x==0 && y==0){
		cout<<"YES"<<endl;
		return;
	}
	cout<<"NO"<<endl;
	


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
