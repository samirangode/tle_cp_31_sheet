#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(){
	ll n, x;

	cin>>n>>x;

	vector<ll> a(n);
	vector<ll> ans;
	for(int i = 0; i<n; i++){
		cin>>a[i];
	}

	sort(a.begin(), a.end());
	int i = 0, j = n-1;
	ll pre = 0;
	ll val = 0;
	while(i<=j){
		if(a[j]==x){
			ans.push_back(a[j]);
			val+=a[j];
			pre = (pre%x + a[j]%x)%x;
			j--;
		}
		else if((pre%x) + a[j] < x){
			//pre+=a[i];
			pre = (pre%x + a[i]%x)%x;
			ans.push_back(a[i]);
			i++;
		}
		else{
			// ans.push_back(a[i]);
			ans.push_back(a[j]);
			val+=a[j];
			// pre = ((pre%x + a[i]%x)%x + a[j]%x)%x;
			pre = (pre%x + a[j]%x)%x;
			//i++;
			j--;
			
		}
	}

	cout<<val<<endl;
	//for(int i = 0; i<n; i++){
	//	cout<<ans[i]<<" ";
	//}
	for(ll temp : ans){
		cout<<temp<<" ";
	}
	cout<<endl;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin>>t;
	while(t--){
		solve();
	}
}
