// #include <bits/stdc++.h>

// using namespace std;

// vector<int> rank;
// vector<int> root;

// void Union(int X, int Y){

// }

// int findRooot(int n){

// }

// void solve(){
//     int n, k;
//     cin>>n>>k;

//     vector<vector<int>> adjList(n+1);

//     for(int i = 1; i<=n-1; i++){
//         int u, v, x;
//         cin>>u>>v>>x;
//         if(x==0){
//             adjList[u].push_back(v);
//             adjList[v].push_back(u);
//         }
//     }

    





// }

// int main(){
//     ios_base::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int t;
//     t = 1;
//     while(t--){
//         solve();
//     }

// }

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long

const int N = 2e5 + 5;
const int MOD = 1e9 + 7;

int n, k, sz, ans = 0;
bool vis[N];
vector<vector<int>> adjList(N);

int pow(int a, int b, int m){
    int ans =  1;

    while(b>0){
        if(b&1)
            ans = (ans*a)%m;

        b = b>>1;
        a = (a*a)%m;
    }
    return ans;
}

void dfs(int u){
    vis[u] = 1;
    sz++;
    for(auto child : adjList[u]){
        if(!vis[child]){
            dfs(child);
        }
    }
}

int32_t main(){
    IOS;

    cin>>n>>k;
    int ans = pow(n, k, MOD);
    for(int i = 1; i<=n-1; i++){
        int u, v, x;
        cin>>u>>v>>x;
        if(x==0)
            adjList[u].push_back(v), adjList[v].push_back(u);
    }

    for(int i =1; i<=n; i++){
        if(vis[i]) continue;

        sz = 0;
        dfs(i);
        ans-=pow(sz,k,MOD);
        ans+=MOD;
        ans%=MOD;
    }
    cout<<ans<<endl;
    return 0;
}