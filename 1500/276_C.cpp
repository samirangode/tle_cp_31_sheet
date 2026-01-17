#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve(){
    int n, q;
    cin>>n>>q;

    vector<int> a(n);

    for(int i = 0; i<n; i++){
        cin>>a[i];
    }

    vector<pair<int,int>> queries(q);
    for(int i = 0; i<q; i++){
        int l, r;
        cin>>l>>r;
        queries[i] = {l,r};
    }

    vector<int> occ(n+2);

    for(auto it : queries){
        occ[it.first]++;
        occ[it.second+1]--;
    }

    priority_queue<int> pq;
    for(int i =1; i<=n; i++){
        occ[i] = occ[i] + occ[i-1];
        pq.push(occ[i]);
    }

    ll sum = 0;
    sort(a.begin(), a.end(), greater<int>());
    int i = 0;
    
    while(!pq.empty()){
        int freq = pq.top();
        pq.pop();
        sum = sum + 1ll*freq*a[i];
        i++;
    }
    cout<<sum<<endl;

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}
