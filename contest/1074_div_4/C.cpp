#include <bits/stdc++.h>
using namespace std;

// typedef long long ll;
#define int long long

void solve(){
	int n;
	cin>>n;
    vector<int> a(n);
    set<int> s;
	for(int i = 0; i<n; i++){
		cin>>a[i];
        s.insert(a[i]);
	}
    int cur_len = 1;
    int max_len = 1;
    for(auto it = s.begin(); it!=s.end(); it++){
        auto next_it = it;
        next_it++;
        if(next_it==s.end()){
            break;
        }
        if((*next_it)-(*it)==1){
            cur_len++;
            max_len = max(max_len, cur_len);
        }
        else{
            cur_len = 1;
        }
    }
	cout<<max_len<<endl;

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