#include <bits/stdc++.h>
using namespace std;

// typedef long long ll;
#define int long long

int32_t main(){
	vector<int> a = {0,6};
	vector<int> b = {0,6};

	vector<vector<int>> bita(2, vector<int>(32));
	vector<vector<int>> bitb(2, vector<int>(32));
	for(int i = 1; i<2; i++){
		int x = a[i];
		int y = b[i];
		for(int k = 0; k<32; k++){
			bita[i][31-k] = (x>>k)&1;
		}
		for(int k = 0; k<32; k++){
			bitb[i][31-k] = (y>>k)&1;
		}
	}
	for(int i = 1; i< a.size(); i++){
		for(int k = 0; k<32; k++){
			cout<<bita[i][k]<<" ";
		}
	}

}
