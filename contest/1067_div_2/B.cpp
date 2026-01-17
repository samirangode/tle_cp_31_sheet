#include <bits/stdc++.h>
using namespace std;

// typedef long long ll;
#define int long long

void solve(){
	int n;
	cin>>n;
	vector<int> arr(2*n);

	for(int i = 0; i<2*n; i++) cin>>arr[i];

	unordered_map<int, int> freq;
	for(int x : arr){
		freq[x]++;
	}
	vector<int> freq_v;
	for(auto it : freq){
		freq_v.push_back(it.second);
	}
	int count = 0, a = 0, b = 0;
	for(int x : freq_v){
		if(x&1){ // odd
			b++;
		}
		else{
			int k = x/2;
			if(k&1) count++;
			else a++;
		}
	}

	// if(b>0)
	// 	count+=b;
	 

	count +=a;
	if(a>0 && a&1){
		if(b==0) count-=1;
	}

	int ans = 2*count + b;
	cout<<ans<<endl;
	// if(a>0){
	// 	if(a%2==0){
	// 		count+=a;
	// 	}
	// 	else{
	// 		if(b>0){
	// 			count+=a;
	// 		}
	// 		else{
	// 			count+=(a-1);
	// 		}
	// 	}
	// }
	

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
