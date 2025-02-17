#include <bits/stdc++.h>

using namespace std;

// void dfsOnF(int u, int v, vector<unordered_set<int>>&  adjF, vector<unordered_set<int>>&  adjG, vector<bool>& visitedF, int& rem){
//     visitedF[u] = true;
//     for(auto it : adjF[u]){
//         if(adjG[u].find(it)!=adjG[u].end()){
//             //removal
//             rem++;
            
//         }
//     }

// }

// void dfsOnG(int u, int v, vector<unordered_set<int>>&  adjF, vector<unordered_set<int>>&  adjG, vector<bool>& visitedG){

//     for(int c : adjG[u]){

//     }

// }
struct DSU{
    int n;
    vector<int> parent, rank, 

};

void solve(){
    int n, m1, m2;
    cin>>n>>m1>>m2;

    vector<vector<int>> adjF(n), adjG(n);
    for(int i = 0; i<m1; i++){
        int u, v;
        cin>>u>>v;
        adjF[u-1].push_back(v-1);
        adjF[v-1].push_back(u-1);
    }

    for(int i = 0; i<m2; i++){
        int u, v;
        cin>>u>>v;
        adjG[u-1].push_back(v-1);
        adjG[v-1].push_back(u-1);
    }

}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}