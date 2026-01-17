#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct SegTreeGCD{
    int n;
    
    vector<ll> tree;

    SegTreeGCD(){}

    SegTreeGCD(const vector<ll>& a){
        build(a);
    }

    void build(const vector<ll>& a){
        n = (int)a.size();
        if(n==0){
            tree.clear();
            return;
        }
        tree.assign(4*n, 0);
        build(1, 0, n-1, a);
    }

    void build(int node, int l, int r, const vector<ll>& a){
        if (l==r) {
            tree[node] = a[l];
            return;
        }
        int mid = (l+r)/2;
        build(node*2, l, mid, a);
        build(node * 2 + 1, mid + 1, r, a);

        tree[node] = std::gcd(tree[node * 2], tree[node * 2 + 1]);
    }

    ll query(int ql, int qr){
        if(n==0 || ql>qr) return 0;
        return query(1, 0, n - 1, ql, qr);
    }

    ll query(int node, int l, int r, int ql, int qr){
        if (qr < l || r < ql) {
            return 0; // gcd identity
        }
        if (ql <= l && r <= qr) {
            return tree[node];
        }
        int mid = (l + r) / 2;
        ll leftG = query(node * 2, l, mid, ql, qr);
        ll rightG = query(node * 2 + 1, mid + 1, r, ql, qr);
        return std::gcd(leftG, rightG);
    }
};

void solve(){
    int n, q;
    cin>>n>>q;
    vector<ll> a(n);

    for(int i = 0; i<n; i++) cin>>a[i];

    vector<ll> b;
    b.reserve(max(0, n - 1));
    for (int i = 0; i + 1 < n; ++i) {
        b.push_back(llabs(a[i] - a[i + 1]));
    }

    SegTreeGCD seg(b);

    while(q--){
        int l, r;
        cin >> l >>r;
        if(l==r){
            cout<<0<<" ";
            continue;
        }

        int l0 = l - 1;
        int r0 = r - 1;
        int ql = l0;
        int qr = r0 - 1;
        ll g = seg.query(ql, qr);
        cout<<g<<" ";
    }
    cout<<"\n";
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