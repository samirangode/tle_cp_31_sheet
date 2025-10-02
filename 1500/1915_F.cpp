#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define Oset tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
// order_of_key(k) : no. of elements < k
// *find_by_order(i) : value at index i (0-based)
typedef long long ll;



// void solve(){
//     int n;
//     cin>>n;
//     vector<pair<int,int>> seg(n);
//     for(int i = 0; i<n; i++){
//         cin>>seg[i].first>>seg[i].second;
//     }
//     sort(seg.begin(), seg.end());
//     Oset st;
//     long long ans = 0;
//     for(int i = 0; i < n; i++){
//         ans+= i - st.order_of_key(seg[i].second);
//         st.insert(seg[i].second);
//     }
//     cout<<ans<<endl;

// }
struct BIT{
    int n; vector<ll> f;
    BIT(int n): n(n), f(n+1, 0) {}
    void add(int i, long long v=1){
        for(; i<=n; i+=i&-i) f[i]+=v;
    }
    long long sum(int i){
        long long s=0;
        for(; i>0; i-=i&-i) s+=f[i];
        return s;
    }
};
void solve(){
    int n;
    cin>>n;
    vector<pair<int,int>> seg(n);
    for(int i = 0; i<n; i++){
        cin>>seg[i].first>>seg[i].second;
    }
    sort(seg.begin(), seg.end());
    
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
