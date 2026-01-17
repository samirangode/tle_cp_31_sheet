#include <bits/stdc++.h>
using namespace std;

// typedef long long ll;
#define int long long

void solve(){
	int n, k;
    cin>>n>>k;
    
    if(k>=31){
        cout<<0<<endl;
        return;
    }
    int max_reachable = 1<<(k-1);
    cout<<max(0LL, n - max_reachable)<<endl;
    
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