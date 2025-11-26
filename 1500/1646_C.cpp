// #include <bits/stdc++.h>
// using namespace std;

// #define int long long

// set<int> vals;

// void solve(){
// 	int n;
// 	cin>>n;

// 	vector<int> temp_vals;

// 	int ans = 0;
// 	while(n>0){
// 		auto it = vals.upper_bound(n);
// 		it--;
// 		int cand = *it;
// 		temp_vals.push_back(cand);	
// 		vals.erase(it);
// 		n-=cand;
// 		ans++;
// 	}	
// 	for( int val : temp_vals){
// 		vals.insert(val);
// 	}
// 	cout<<ans<<endl;
// 	// find the element just smaller than n;
// 	// reduce and remove that element from vals
// 	// but keep it stored in another ds
// 	// at the end all those elements back into vals.
// }

// int32_t main(){
// 	ios_base::sync_with_stdio(false);
// 	cin.tie(nullptr);

// 	// factorial till 15
// 	// power till 40
// 	int fac = 1;
// 	for(int i = 1; i<15; i++){
// 		fac = fac*i;
// 		vals.insert(fac);
// 	}
// 	for(int i = 0; i<=40; i++){
// 		vals.insert(1ll<<i);
// 	}


// 	int t;
// 	cin>>t;
// 	while(t--){
// 		solve();
// 	}


// }


#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

	// Precompute factorials of 3!, 4! ... till 1e12
	vector<i64> facts;
	__int128_t f = 1;

	for(int d = 1; ;++d){
		f*=d;
		if(f>(__int128_t)1e12) break;
		if(d>=3) facts.push_back((i64)f);
	}

	const int m = (int)facts.size();

	int T;
	cin>>T;
	while(T--){
		i64 n;
		cin>>n;

		int best = __builtin_popcountll(n);

		for(int mask = 1; mask < (1<<m); mask++){
			__int128_t sum = 0;
			int cnt = 0;
			for(int i = 0; i<m; i++){
				if(mask & (1<<i)){
					sum+=facts[i];
					cnt++;
					if(sum>n) break;
				}
			}

			if(sum>n) continue;
			i64 rem = (i64)(n - sum);
			best = min(best, cnt + __builtin_popcountll(rem));

		}
		cout<<best<<endl;
	}



}