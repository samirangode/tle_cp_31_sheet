#include <bits/stdc++.h>
using namespace std;

// typedef long long ll;
#define int long long

void solve(){
	int n, m, k;
    cin>>n>>m>>k;
    vector<int> a(n), b(m);
    for(int i = 0; i<n; i++){
        cin>>a[i];
    }
    for(int i = 0; i<m; i++){
        cin>>b[i];
    }
    string s;
    cin>>s;
    unordered_map<int, vector<int>> kill_left;
    unordered_map<int, vector<int>> kill_right;
    sort(b.begin(), b.end());
    for(int i = 0; i<n; i++){
        int spike_right = upper_bound(b.begin(), b.end(), a[i]) - b.begin();
        int spike_left = spike_right - 1;
        if(spike_left>=0){
            int step_left = a[i] - b[spike_left];
            kill_left[step_left].push_back(i);
        }
        if(spike_right < m){
            int step_right = b[spike_right] - a[i];
            kill_right[step_right].push_back(i);
        }
    }

    unordered_set<int> killed;
    int curr = 0;
    int max_l = 0;
    int max_r = 0;
    for(int i = 0; i<k; i++){
        if(s[i]=='L'){
           curr--;
           if(curr < max_l){
               max_l = curr;
               for(int idx : kill_left[-max_l])
                   killed.insert(idx);
            }
        }
        if(s[i]=='R'){
           curr++;
           if(curr > max_r){
               max_r = curr;
               for(int idx : kill_right[max_r])
                   killed.insert(idx);
            }
        }
        cout<<n - killed.size()<<" ";
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