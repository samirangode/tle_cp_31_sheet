// #include <bits/stdc++.h>

// using namespace std;

// void solve(){
//     int n;
//     cin>>n;
//     vector<vector<int>> adj(n+1);

//     for(int i = 0; i<(n-1); i++){
//         int u, v;
//         cin>>u>>v;
//         adj[u].push_back(v);
//         adj[v].push_back(u);
//     }

//     vector<int> depth(n+1,0);
//     vector<int> parent(n+1, 0);
//     vector<int> order;
//     order.reserve(n);

//     {
//         // iterative dfs
//         stack<int> st;
//         st.push(1);
//         parent[1] = 0;
//         depth[1] = 0;
//         while(!st.empty()){
//             int u = st.top();
//             st.pop();
//             order.push_back(u);
//             for(int v : adj[u]){
//                 if(v == parent[u]) continue;
//                 parent[v] = u;
//                 depth[v] = depth[u] + 1;
//                 st.push(v);
//             }
//         }
//     }

//     // compute b[u] max depth in the subtree of u
//     vector<int> b(n+1);
//     int maxDepth = 0;
//     for(int u = 1; u<=n; u++){
//         b[u] = depth[u];
//         maxDepth = max(maxDepth, depth[u]);
//     }

//     // process nodes in the reverse order to calculate b[u]
//     for(int i = (int)order.size(); i>=0; i--){
//         int u = order[i];
//         for(int v : adj[u]){
//             if(v==parent[u]) continue;
//             b[u] = max(b[u], b[v]);
//         }
//     }

//     // Now to find the d that intersect most intervals, sweep algorithm using diff
//     vector<int> diff(maxDepth + 3, 0);
//     for(int u = 1; u<=n; u++){
//         int L = depth[u];
//         int R = b[u];
//         diff[L] += 1;
//         diff[R+1] -= 1;
//     }

//     int cur = 0;
//     int best = 0;

//     for(int d = 0; d<=maxDepth; d++){
//         cur += diff[d];
//         best = max(best, cur);
//     }

//     int answer = n - best;
//     cout<<answer<<"\n";
// }

// int main(){
//     ios_base::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int t;
//     cin>>t;
//     while(t--){
//         solve();
//     }
// }

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<vector<int>> adj(n + 1);
        for (int i = 0; i < n - 1; ++i) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        // 1. Root the tree at 1, compute depths and parents with iterative DFS/BFS
        vector<int> depth(n + 1, 0);
        vector<int> parent(n + 1, 0);
        vector<int> order;
        order.reserve(n);

        {
            // iterative DFS
            stack<int> st;
            st.push(1);
            parent[1] = 0;
            depth[1] = 0;
            while (!st.empty()) {
                int u = st.top();
                st.pop();
                order.push_back(u);
                for (int v : adj[u]) {
                    if (v == parent[u]) continue;
                    parent[v] = u;
                    depth[v] = depth[u] + 1;
                    st.push(v);
                }
            }
        }

        // 2. Compute b[u] = max depth in subtree of u (bottom-up)
        vector<int> b(n + 1);
        int maxDepth = 0;
        for (int u = 1; u <= n; ++u) {
            b[u] = depth[u];
            maxDepth = max(maxDepth, depth[u]);
        }

        // process nodes in reverse order (children before parents)
        for (int i = (int)order.size() - 1; i >= 0; --i) {
            int u = order[i];
            for (int v : adj[u]) {
                if (v == parent[u]) continue;
                b[u] = max(b[u], b[v]);
            }
        }

        // 3. Build difference array for intervals [depth[u], b[u]]
        vector<int> diff(maxDepth + 3, 0); // +3 to be safe with r+1
        for (int u = 1; u <= n; ++u) {
            int L = depth[u];
            int R = b[u];
            diff[L] += 1;
            diff[R + 1] -= 1;
        }

        // 4. Sweep to find max coverage
        int cur = 0;
        int best = 0;
        for (int d = 0; d <= maxDepth; ++d) {
            cur += diff[d];
            best = max(best, cur);
        }

        int answer = n - best;
        cout << answer << "\n";
    }

    return 0;
}
