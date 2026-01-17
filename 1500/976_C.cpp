#include <bits/stdc++.h>

using namespace std;

#define int long long

struct Seg{
    int l, r, ind;
};

void solve(){
    int n;
    cin>>n;

    vector<Seg> a(n);
    for(int i = 0; i<n; i++){
        int u, v;
        cin>>u>>v;
        a[i].l = u;
        a[i].r = v;
        a[i].ind = i+1;
    }

    // sort(a.begin(),a.end(),[&](Seg a, Seg b){
    //     if(a.l<b.l){
    //         return true;
    //     }
    //     else if(a.l==b.l){
    //         if(a.r>=b.r){
    //             return true;
    //         }
    //         else{
    //             return false;
    //         }
    //     }
    //     else{
    //         return false;
    //     }
    // });

    sort(a.begin(), a.end(), [](const Seg& A, const Seg& B) {
        if (A.l != B.l) return A.l < B.l;
        if (A.r != B.r) return A.r > B.r; // longer (larger r) first
        return A.ind < B.ind;             // tie-break to ensure strict order
    });

    // calculate suffix min
    vector<int> suff_min(n+1, INT_MAX);
    vector<int> suff_min_ind(n+1);

    for(int i = n-1; i>=0; i--){
        if(a[i].r<suff_min[i+1]){
            suff_min[i] = a[i].r;
            suff_min_ind[i] = a[i].ind;
        }
        else{
            suff_min[i] = suff_min[i+1];
            suff_min_ind[i] = suff_min_ind[i+1];
        }
    }

    for(int i = 0; i<(n-1); i++){
        // check if any possible internal segment exists at each segment
        if(a[i].r >= suff_min[i+1]){
            // cout<<a[i].ind<<" "<<suff_min_ind[i+1]<<endl;
            cout<<suff_min_ind[i+1]<<" "<<a[i].ind<<endl;
            return;
        }
    }

    cout<<-1<<" "<<-1<<endl;


}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}