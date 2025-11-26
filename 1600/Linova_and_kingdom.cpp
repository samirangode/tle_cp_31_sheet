// #include <bits/stdc++.h>

// using namespace std;

// long long dfs(int i, vector<vector<int>>& adj, 
//             unordered_set<int>& dev_city, int prev, int level){

//                 long long ans = 0;

//                 for(int child : adj[i]){
//                     if(child==prev) continue;
//                     if(dev_city.find(child)!=dev_city.end()){
//                         ans += dfs(child,adj, dev_city,i,level) + level;
//                     }
//                     else{
//                         ans += dfs(child, adj, dev_city, i, level+1);
//                     }
//                 }

//                 return ans;
//             }

// void solve(vector<vector<int>>& adj, int k){

//     int n = adj.size();
//     vector<bool> visited(n,false);
//     unordered_set<int> dev_city;
//     queue<int> q;
//     q.push(0);
//     int num_visited = 0;
    
//     while(!q.empty()){
//         int curr = q.front();
//         q.pop();
//         visited[curr] = true;
//         num_visited++;
//         if(num_visited>(n-k)){
//            dev_city.insert(curr);
//         }
//         for(int child : adj[curr]){
//             if(!visited[child]){
//                 q.push(child);
//             }
//         }
//     }

//     long long sum = dfs(0,adj,dev_city,-1, 1);

//     cout<<sum<<endl;

// }


// int main(){
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);

//     int n,k;
//     cin>>n;
//     cin>>k;

//     vector<vector<int>> adj(n);

//     for(int i= 0; i<(n-1); i++){
//         int a, b;
//         cin>> a;
//         cin>> b;
//         adj[a-1].push_back(b-1);
//         adj[b-1].push_back(a-1);
//     }

//     solve(adj, k);



// }


#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200005;
vector<int> adj[MAXN];
int siz[MAXN], dep[MAXN];
vector<int> happiness;

void dfs(int v, int p = -1, int d = 0) {
    dep[v] = d;
    siz[v] = 1; // Including the current node
    for (int u : adj[v]) {
        if (u == p) continue; // Skip the parent node
        dfs(u, v, d + 1);
        siz[v] += siz[u];
    }
    // Calculate happiness contribution if this node is made tourist
    // and not the root node
    if (v != 1) {
        happiness.push_back(siz[v] - dep[v]);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    // Read the tree edges
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // DFS to compute sizes and depths
    dfs(1);

    // Sort the happiness gain values in descending order
    sort(happiness.begin(), happiness.end(), greater<int>());

    // Calculate maximum happiness by selecting the top (n-k) tourism cities
    long long maxHappiness = 0;
    int touristCities = n - k;
    for (int i = 0; i < touristCities; i++) {
        maxHappiness += happiness[i];
    }

    // Output the result
    cout << maxHappiness << "\n";

    return 0;
}

