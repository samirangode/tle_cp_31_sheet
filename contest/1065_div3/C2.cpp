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
	// First create the bit representation for each array
	vector<vector<int>> bita(n+1, vector<int>(32));
	vector<vector<int>> bitb(n+1, vector<int>(32));
	for(int i = 1; i<=n; i++){
		int x = a[i];
		int y = b[i];
		for(int k = 0; k<32; k++){
			bita[i][31-k] = (x>>k)&1;
		}
		for(int k = 0; k<32; k++){
			bitb[i][31-k] = (y>>k)&1;
		}
	}
	
	int win_outcome = 0; // tie unless someone wins

	for(int j = 0; j<32; j++){

		int a1 = 0, b1 = 0;
		for(int i = 1; i<=n; i++){
			if(bita[i][j]==1) a1++;
			if(bitb[i][j]==1) b1++;	
		}
		if((a1&1)==(b1&1)){
			// cout<<"Tie"<<endl;
			continue;
		}
		int i = n;
		for(; i>=1; i--){
			if(bita[i][j]!=bitb[i][j]){
				break;
			}
		}
		if(i<1){
			// cout<<"Tie"<<endl;
			// return;
			continue;
		}
		if(i&1){
			// cout<<"Ajisai"<<endl;
			win_outcome = 1;
			break;
		}
		else{
			// cout<<"Mai"<<endl;
			win_outcome =  2;
			break;
		}

	}

	if(win_outcome==0){
		cout<<"Tie"<<endl;
		return;
	}
	if(win_outcome==1){
		cout<<"Ajisai"<<endl;
		return;
	}
	if(win_outcome==2){
		cout<<"Mai"<<endl;
		return;
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
