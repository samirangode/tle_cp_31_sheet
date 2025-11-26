#include <bits/stdc++.h>
using namespace std;

// typedef long long ll;
#define int long long

void solve(){
	int n;
	cin>>n;
	vector<int> a(n);
	for(int i = 0; i<n; i++) cin>>a[i];

	if(a[0]==-1 || a[n-1]==-1){
		if(a[0]==-1 && a[n-1]==-1){
			a[0] = 0;
			a[n-1] = 0;
		}
		else if(a[0]==-1){
			a[0] = a[n-1];
		}
		else{
			a[n-1] = a[0];
		}
		cout<<abs(a[0] - a[n-1])<<endl;

	}
	else{
		cout<<abs(a[0] - a[n-1])<<endl;;
	}

	for(int i = 0; i<n; i++){
		if(a[i]==-1) a[i] = 0;
		cout<< a[i] <<" ";
	}
	cout<<endl;


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
