#include <bits/stdc++.h>
using namespace std;


void solve(){
	int n;
	cin>>n;
	vector<int> a(n);
	int num_odd = 0;
	for(int i = 0; i<n; i++){
		cin>>a[i];
		if(a[i]&1) num_odd++;
	}
	if(!(num_odd == 0 || num_odd==n)){
		sort(a.begin(), a.end());	
	}
	for(int i = 0; i<n; i++){
		cout<<a[i]<<" ";
	}
	cout<<endl;

	
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
