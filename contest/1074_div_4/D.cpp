#include <bits/stdc++.h>
using namespace std;

// typedef long long ll;
#define int long long

void solve(){
	int n,m,h;
	cin>>n>>m>>h;
    vector<int> a(n+1);
	for(int i = 1; i<=n; i++){
		cin>>a[i];
	}
    vector<pair<int,int>> b(m);
    for(int i = 0; i<m; i++){
        int u, v;
        cin>>u>>v;
        b[i].first = u;
        b[i].second = v;
    }

    
    vector<int> deltas(n+1, 0);
    vector<int> seen(n+1, 0);
    int gen = 0;
    for(int i = 0; i<m; i++){
        int ind = b[i].first;
        int val = b[i].second;
        if(seen[ind]!=gen){
            seen[ind] = gen;
            deltas[ind] = 0;
        }
        if(a[ind] + deltas[ind] + val > h){
            gen++;
        }
        else{
            deltas[ind]+=val;
        }
    }
    for(int i =1 ;i<=n; i++){
        if(seen[i]==gen){
            a[i]+=deltas[i];
        }
        cout<<a[i]<<" ";
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