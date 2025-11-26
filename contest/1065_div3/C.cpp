#include <bits/stdc++.h>
using namespace std;

// typedef long long ll;
#define int long long

void solve(){
	int n;
	cin>>n;
	vector<int> a(n+1);
	vector<int> b(n+1);
	for(int i =1; i<=n; i++) cin>>a[i];
	for(int i =1; i<=n; i++) cin>>b[i];

	// count number of 1s for each
	int a1 = 0, b1 = 0;
	for(int i = 1; i<=n; i++){
		if(a[i]==1) a1++;
		if(b[i]==1) b1++;	
	}
	if((a1&1)==(b1&1)){
		cout<<"Tie"<<endl;
		return;
	}
	int i = n;
	for(; i>=1; i--){
		if(a[i]!=b[i]){
			break;
		}
	}
	if(i<1){
		cout<<"Tie"<<endl;
		return;
	}
	if(i&1){
		cout<<"Ajisai"<<endl;
	}
	else{
		cout<<"Mai"<<endl;
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
