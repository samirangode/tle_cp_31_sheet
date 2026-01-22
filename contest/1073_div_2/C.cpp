#include <bits/stdc++.h>
using namespace std;

// typedef long long ll;
#define int long long

void solve(){
	int n;
	cin>>n;
	string s;
	cin>>s;
	string s_sort = s;
	sort(s_sort.begin(), s_sort.end());

	vector<int> ans;
	for(int i = 0; i<n; i++){
		if(s[i]!=s_sort[i]){
			ans.push_back(i+1);
		}
	}

	if(ans.empty()){
		cout<<"Bob"<<endl;
	}
	else{
		cout<<"Alice"<<endl;
		cout<<ans.size()<<endl;
		for(int v : ans){
			cout<<v<<" ";
		}
		cout<<endl;
	}

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
