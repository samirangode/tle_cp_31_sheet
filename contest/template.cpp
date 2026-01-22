#include <bits/stdc++.h>
using namespace std;

// typedef long long ll;
#define int long long

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15ULL;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9ULL;
        x = (x ^ (x >> 27)) * 0x94d049bb133111ebULL;
        return x ^ (x >> 31);
    }
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM =
            chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

struct pair_hash {
    size_t operator()(const pair<long long,long long>& p) const {
        static custom_hash h;
        // combine two 64-bit hashes
        return h((uint64_t)p.first) ^ (h((uint64_t)p.second) << 1);
    }
};

// usage:
// unordered_map<long long, int, custom_hash> mp;
// unordered_set<long long, custom_hash> st;
// unordered_map<pair<long long,long long>, int, pair_hash> mp2;
// usage 2:
// unordered_map<long long, vector<int>, custom_hash> mp;
// mp.reserve(n * 2);
// mp.max_load_factor(0.7);


void solve(){
	int n;
	cin>>n;
	for(int i = 1; i<=n; i++){
		cout<<i<<" ";
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