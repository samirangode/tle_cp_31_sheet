#include <bits/stdc++.h>

using namespace std;

// #define ll long long;
typedef long long ll;
const ll N = 2e5 + 2;
const ll C = 10 +1;

vector<ll> parent(N);
vector<ll> set_size(N, 1);
vector<vector<ll>> net_sequences(N, vector<ll>(C,0));
vector<vector<ll>> component_leader(N, vector<ll>(C,0));
vector<vector<ll>> start_count(N, vector<ll>(C, 0));
vector<vector<ll>> end_count(N, vector<ll>(C, 0));

// int findRoot(int x, vector<int>& root){
//     if(root[x]!=x){
//         root[x] = findRoot(root[x],root);
//     }
//     return root[x];
// }

// void rankUnion(int x, int y, vector<int>& root, vector<int>& rank){
//     int rootX = findRoot(x, root);
//     int rootY = findRoot(y, root);

//     if(rootX==rootY) return;

//     if(rank[rootX]>rank[rootY]){
//         root[rootY] = rootX;
//     }
//     else if(rank[rootX] < rank[rootY]){
//         root[rootX] = rootY;
//     }
//     else{
//         root[rootY] = rootX;
//         rank[rootX]+=1;
//     }
// }


// int main(){
//     ios_base::sync_with_stdio(0);
//     cin.tie(nullptr);

//     int t;
//     cin>>t;
//     while(t--){
//         int n, m;
//         cin>>n;
//         cin>>m;

//         vector<int> root(n+1);
//         iota(root.begin(), root.end(),0);

//         vector<int> rank(n+1,1);

//         int a, d, k;
//         for(int f = 0; f<m; f++){
//             cin>>a;
//             cin>>d;
//             cin>>k;

//             int root_prev = findRoot(a,root);
//             for(int t = 1; t<=k; t++){
//                 int ele = a + t*d;
//                 rankUnion(root_prev, ele, root, rank);
//                 root_prev = findRoot(ele, root);
//             }
//         }

//         //check from 1 for different roots;
//         unordered_set<int> us;
//         for(size_t i=1; i<root.size(); i++){
//             // us.insert(root[i]);
//             us.insert(findRoot(i,root));
//         }
//         cout<<us.size()<<endl;

//     }

// }

ll find_parent(ll a){
        if(parent[a] == a) return a;
        return parent[a] = find_parent(parent[a]);
}

void unite(ll a, ll b) {
    a = find_parent(a);
    b = find_parent(b);

    if(a==b) return;
    if (set_size[b] > set_size[a]) swap(a, b);
    set_size[a] += set_size[b];
    parent[b] = a;
}

void reset(ll n) {
    for (ll i = 1; i <= n; i++) {
        parent[i] = i;
        set_size[i] = 1;
        for (ll d = 1; d < C; d++) {
            net_sequences[i][d] = 0;
            start_count[i][d] = 0;
            end_count[i][d] = 0;
            component_leader[i][d] = i;
        }
    }
}

void solve(){
    ll n, m;
    cin >> n >> m;    

    reset(n);

    for(ll i = 0; i<m; i++){
        ll a, d, k;
        cin>>a>>d>>k; 

        start_count[a][d]++;
        end_count[a+k*d][d]++;
    }

    for(ll i = 1; i<=n; i++){
        for(ll d =1; d<C; d++){
            net_sequences[i][d] = start_count[i][d] - end_count[i][d];

            if(i - d>=1 && net_sequences[i-d][d]>0){
                unite(component_leader[i-d][d], i);
                component_leader[i][d] = component_leader[i-d][d];
                net_sequences[i][d]+=net_sequences[i-d][d];
            }
        }
    }

    ll ans = 0;
    for(ll i = 1; i<=n; i++){
        if(find_parent(i) == i) ans++;
    }

    cout<<ans<<endl;
}



int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}