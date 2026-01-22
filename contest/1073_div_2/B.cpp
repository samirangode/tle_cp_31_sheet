#include <bits/stdc++.h>
using namespace std;

// typedef long long ll;
#define int long long

void solve(){
	int n;
	cin>>n;
	vector<int> a(n);
	int num_zeros = 0;
	int num_ones = 0;
	for(int i = 0; i<n; i++){
		cin>>a[i];
		if(a[i]==0) num_zeros++;
		if(a[i]==1) num_ones++;
	}

	if(num_zeros>0){
		if(num_zeros==1){
			cout<<"YES"<<endl;
		}
		else{
			if(num_ones>0){
				cout<<"YES"<<endl;
			}
			else{
				cout<<"NO"<<endl;
			}
		}
	}
	else{
		cout<<"NO"<<endl;
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
