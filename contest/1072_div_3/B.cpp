#include <bits/stdc++.h>
using namespace std;

// typedef long long ll;
#define int long long

void solve(){
	int s, k, m;
    cin>>s>>k>>m;

    // if s <= k
    if(s<=k){
        int mod = m % k;
        if(mod>=s){
            cout<<0<<endl;
        }
        else{
            cout<<s-mod<<endl;
        }
    }
    else{
        // k < s
        int mod = m % k;
        int div = m / k;
        if(div==0){
            // m < k < s
            cout<<s-mod<<endl;
        }
        else if(div%2==0){
            // full avail
            cout<<s-mod<<endl;
        }
        else{
            cout<<k-mod<<endl;
        }
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