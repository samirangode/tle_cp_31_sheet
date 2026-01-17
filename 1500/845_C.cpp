// I do the +1 , -1 trick for all 2*10^5 values and then take the prefix sum.
// If at any point there are more than 2, not possible

#include <bits/stdc++.h>

using namespace std;

typedef long long ll; 

int max_val = 2*1e5+10;
vector<int> occ(max_val);

void solve(){
    int n;
    cin>>n;

    // vector<vector<int>> seg(n);
    // for(int i = 0; i<n; i++){
    //     int u, v;
    //     cin>>u>>v;
    //     seg[i].push_back(u);
    //     seg[i].push_back(v);
    // }
    // sort(seg.begin(),seg.end());

    // for(auto p : seg){
    //     occ[p[0]]+=1;
    //     occ[p[1]+1]-=1;
    // }

    // for(int i = 1; i<max_val; i++){
    //     occ[i] = occ[i] + occ[i-1];
    //     if(occ[i]>2){
    //         cout<<"NO"<<endl;
    //         return;
    //     }
    // }

    // cout<<"YES"<<endl;

    vector<pair<ll, int>> events;
    for(int i = 0; i<n; i++){
        ll l, r;
        cin>>l>>r;
        events.push_back({l, 1});
        events.push_back({r, -1});
    }

    sort(events.begin(), events.end(), [&](auto &A, auto &B){
        if(A.first != B.first) return A.first<B.first;

        return A.second>B.second;
    });

    ll cur = 0;
    for(auto &e : events){
        cur+=e.second;
        if(cur>2){
            cout<<"NO"<<endl;
            return;
        }
    }
    cout<<"YES"<<endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}