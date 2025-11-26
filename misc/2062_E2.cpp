#include <bits/stdc++.h>

using namespace std;

static const int NMAX = 500000 + 2;

// adjacency list for the tree
vector<int> adj[NMAX];

// timeIn[u]: DFS discovery time of node u
// timeOfNode[i]: The node discovered at time i
// low[u]: The maximum DFS time in u's subtree
int timeIn[NMAX], timeOfNode[NMAX], low[NMAX];

// Fenwicks / BIT array for prefix maximums
int fenwicks[NMAX];

// We'll reuse a global DFS counter
int timerGlobal = 0;

inline void updateFenwicks(int pos, int val, int n){
    // update the fenwicks structure so that
    // fenwicks[x] = max(fenwicks[pos], val) for all x
    // covering pos
    for(; pos<=n; pos+=pos&(-pos)){
        fenwicks[pos] = max(fenwicks[pos], val);
    }
}

inline int getMaxFenwicks(int pos){
    // Get the maximum over fenwicks [1:pos]
    int ret = 0;
    for(;pos>0; pos-= pos & (-pos)){
        ret = max(fenwicks[pos], ret);
    }
    return ret;
}

// DFS function

void dfs(int u, int parent){
    // "timerGlobal" increments each time we visit a node
    timerGlobal++;
    timeIn[u] = timerGlobal;
    timeOfNode[timerGlobal] = u;

    // we haven't processed children yet, so initially low[u] = timeIn[u]
    low[u] = timeIn[u];

    for(int v : adj[u]){
        if(v==parent) continue;
        dfs(v,u);
        low[u] = max(low[u], low[v]);
    }

}



int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin >> n;

        for(int i = 1; i<=n; i++){
            adj[i].clear();
            fenwicks[i] = 0; // reset fenwicks array
        }

        timerGlobal = 0;

        // We'll have "buckets[val-1]" hold the nodes whose w[node] = val
        // Because we know node values range from 1..n (presumably),
        // we can store them in an array of vectors. 
        // We'll dynamically build it here.
        vector<vector<int>> buckets(n); 

        // Read node values & place them in the appropriate bucket
        //   i.e., if the i-th node read has value X, then place (i) in buckets[X-1].
        // NOTE: The original code reads them in an unusual manner, but logically
        // it's "node i has value j => buckets[j-1].push_back(i)"
        for(int i = 1; i <= n; i++){
            int val; 
            cin >> val; 
            buckets[val - 1].push_back(i);
        }

        // Read edges, build adjacency
        for(int i = 1; i < n; i++){
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        // DFS from root=1 to get timeIn[], low[], timeOfNode[]
        dfs(/*start=*/1, /*parent=*/-1);



    }
}

