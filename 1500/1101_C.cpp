#include <bits/stdc++.h>

using namespace std;

// void solve(){
//     int n;
//     cin>>n;
//     vector<pair<int,int>> seg(n);
//     vector<int> ind;
//     iota(ind.begin(),ind.end(),0);
    
//     for(int i = 0; i<n; i++){
//         int l ,r;
//         cin>>l>>r;
//         seg[i] = {l,r};
//     }
//     sort(ind.begin(), ind.end(), [&](int a, int b){
//         return seg[a].first<seg[b].first;
//     });
//     sort(seg.begin(), seg.end());

//     int new_block = -1;
//     for(int i = 0; i<n; ){
//         int curr_block_end = upper_bound(seg.begin(), seg.end(), seg[i].second) - seg.begin();
//         if(curr_block_end==n) break;
//         int curr_block_max_r = seg[i].second;
//         for(int j = i ; j<curr_block_end; j++){
//             curr_block_max_r = max(curr_block_max_r, seg[j].second);
//         }

//         curr_block_end = upper_bound(seg.begin(), seg.end(), curr_block_max_r) - seg.begin();
//         if(curr_block_end==n) break;
//         new_block = curr_block_end;
//         break;
//     }

//     if(new_block==-1){
//         cout<<-1<<endl;
//         return;
//     }

//     unordered_set<int> block0;
//     for(int i = 0; i<new_block; i++){
//         block0.insert(ind[i]);
//     }
//     for(int i = 0; i<n; i++){
//         if(block0.find(i)!=block0.end()){
//             cout<<1<<" ";
//         }
//         else{
//             cout<<2<<" ";
//         }
//     }
//     cout<<endl;

// }

struct Seg{
    int l, r, idx;
};

void solve(){
    int n;
    cin>>n;
    vector<Seg> segs(n);
    for(int i =0; i<n; i++){
        cin>>segs[i].l>>segs[i].r;
        segs[i].idx = i;
    }
    sort(segs.begin(), segs.end(), [](Seg a, Seg b){
        if(a.l!=b.l) return a.l< b.l;
        return a.r<b.r;
    });

    vector<int> prefMax(n);
    prefMax[0] = segs[0].r;
    for(int i = 1; i<n; i++) prefMax[i] = max(prefMax[i-1], segs[i].r);

    vector<int> suffMin(n);
    suffMin[n-1] = segs[n-1].l;
    for(int i = n-2; i>=0; i--) suffMin[i] = min(suffMin[i+1], segs[i].l);

    // Find a split point
    int split = -1;
    for (int i = 0; i < n - 1; ++i) {
        if (prefMax[i] < suffMin[i + 1]) {
            split = i;
            break;
        }
    }

    if (split == -1) {
        cout << -1 << '\n';
        return;
    }

    // Build answer in original order
    vector<int> ans(n);
    for (int i = 0; i <= split; ++i) {
        ans[segs[i].idx] = 1;
    }
    for (int i = split + 1; i < n; ++i) {
        ans[segs[i].idx] = 2;
    }

    for (int i = 0; i < n; ++i) {
        cout << ans[i] << (i + 1 == n ? '\n' : ' ');
    }

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin>>t;
    while(t--){
        solve();
    }
}