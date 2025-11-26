#include <bits/stdc++.h>
using namespace std;


void solve(){
	int n;
	cin>>n;
	string s, t;
	cin>>s>>t;
	vector<char> sc(26,0);
	vector<char> tc(26,0);

	for(char c : s){
		sc[c - 'a']++;
	}

	for(char c : t){
		tc[c - 'a']++;
	}

	bool possible = true;
	for(int i = 0; i<26; i++){
		if(sc[i]!=tc[i]){
			possible = false;
		}
	}
	if(possible){
		cout<<"YES"<<endl;
	}
	else{
		cout<<"NO"<<endl;
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
