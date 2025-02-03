#include <bits/stdc++.h>
using namespace std;

struct LCA{
    vector<int> height, euler, first, segTree;
    vector<bool> visited;
    int n;
    LCA(vector<vector<int>> &adj, int root=0){
        n = adj.size();
        height.resize(n);
        first.resize(n);
        euler.reserve(n*2);
        visited.assign(n, false);
        dfs(adj,root);
        int m = euler.size();
        segTree.resize(m*4);
        build(1,0, m-1);
    }
    void dfs(vector<vector<int>> &adj, int node, int h = 0){
        visited[node] = true;
        height[node] = h;
        first[node] = euler.size();
        euler.push_back(node);
        for(int c : adj[node]){
            if(!visited[node]){
                dfs(adj,c,h+1);
                euler.push_back(node);
            }
        }
    }

    void build(int node, int b, int e){
        if(b==e){
            segTree[node] = euler[b];
        }
        else{
            int mid = (b+e)/2;
            build(node<<1, b, mid);
            build(node<<1|1, mid+1, e);
            int l = segTree[node<<1], r = segTree[node<<1|1];
            segTree[node] = height[l]<height[r]? l : r;
        }
    }

    int query(int node, int b, int e, int L, int R){
        if( b> R || e < L){
            return -1;
        }
        if( b >= L && e <= R){
            return segTree[node];
        }
        int mid = (b+e)>>2;

        int left = query(node<<1, b, mid, L, R);
        int right = query(node<<1|1, mid+1, e, L, R);
        if(left == -1) return right;
        if(right == -1) return left;
        return height[left] < height[right] ? left:right;
    }

    int lca(int u, int v){
        int left = first[u], right = first[v];

        if(left>right){
            swap(left,right);
        }

        return query(1, 0, euler.size() - 1, left, right);
    }
};

int main(){

}