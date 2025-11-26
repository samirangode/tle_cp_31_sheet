#include <bits/stdc++.h>
using namespace std;

#define int long long


void solve(){
	int n;
	cin>>n;

	string s;
	cin>>s;

	int c1 = count(s.begin(), s.end(), '+');
	int c2 = n - c1;

	int q;
	cin>>q;

	while(q--){
		int a, b;
		cin>>a>>b;
		if(c1==c2){
			cout<<"YES"<<endl;
			continue;
		}
		if(a==b){
			cout<<"NO"<<endl;
			continue;
		}

		int l = a*b/__gcd(a,b);

		int x = l/a , y = l/b;

		if(abs(c2-c1) % abs(x-y)){
			cout<<"NO"<<endl;
			continue;
		}
		else{
			int p = abs(c2-c1) / abs(x-y);
			if((x+y)*p <=n){
				cout<<"YES"<<endl;
				continue;
			}
			else{
				cout<<"NO"<<endl;
				continue;
			}
		}
		
	}
		
}

int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	solve();
}
