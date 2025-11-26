#include <bits/stdc++.h>
using namespace std;


void solve(){
	int n;
	cin>>n;
	string s;
	cin>>s;

	vector<int> bal(n,0);
	for(int i = 0; i<n; i++){
		bal[i] = ((i>0) ? (bal[i-1]) : (0)) + (s[i]=='(' ? 1 : -1);
	}

	if(bal.back()!=0){
		cout<<-1<<endl;
		return;
	}
	if(*min_element(bal.begin(), bal.end())==0 || 
			*max_element(bal.begin(), bal.end())==0){
		cout<<1<<endl;
		for(int i = 0; i<n; i++){
			cout<<1<<" ";
		}
		cout<<endl;
		return;
	}
	else{
		cout<<2<<endl;
		int cur = 0;
		int val = ((s[0]=='(') ? 1 : 2);
		while(cur<n){
			cout<<val<<" ";
			if(bal[cur]==0 && cur<(n-1)){
				val = (s[cur+1]=='(') ? 1 : 2;
			}
			cur++;
		}
		cout<<endl;
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
