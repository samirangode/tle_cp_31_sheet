#include <bits/stdc++.h>
using namespace std;


void solve(){
	vector<int> sides(4);

	for(int i = 0; i<4; i++){
		cin>>sides[i];
	}
	int val = sides[0];
	bool possible = true;
	for(int i = 1; i<4; i++){
		if(sides[i]!=val){
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
