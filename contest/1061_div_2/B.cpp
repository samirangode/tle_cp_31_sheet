#include <bits/stdc++.h>
using namespace std;


void solve(){
	int n, q;
	cin>>n>>q;

	string s;
	cin>>s;

	int countB = 0;
	for(char c : s){
		if(c=='B') countB++;	
	}


	for(int j = 0; j<q; j++){
		int a;
		cin>>a;	
		if(countB==0){
			cout<<a<<endl;
			continue;
		}
		int ans = 0;
		int i = 0;
		while(a>0){
			char c = s[i];
			if(c=='A'){
				a--;
			}
			else{
				a = a/2;
			}
			ans++;
			i = (i+1)%n;
		}
		cout<<ans<<endl;
	}
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
