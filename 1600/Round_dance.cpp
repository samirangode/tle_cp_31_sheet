#include <bits/stdc++.h>

using namespace std;


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<unordered_set<int>> g(n); // graph
        vector<int> a(n);
        vector<int> d(n); // degrees
        for(int i = 0; i<n; i++){
            cin>>a[i];
            a[i]--;
            g[i].insert(a[i]);
            g[a[i]].insert(i);
        }
        for(int i = 0; i<n; i++){
            d[i] = g[i].size();
        }
        int bamboos = 0, cycles = 0;
        vector<bool> vis(n);
        for(int i = 0; i<n; i++){
            if(!vis[i]){
                queue<int> q;
                q.push(i);
                vis[i] = true;
                vector<int> component = {i};
                while(!q.empty()){
                    int u = q.front();
                    q.pop();
                    for(int m : g[u]){
                        if(!vis[m]){
                            q.push(m);
                            vis[m] = true;
                            component.push_back(m);
                        }
                    }
                }
                bool bamboo = false;
                for(int j : component){
                    if (d[j]==1){
                        bamboo = true;
                        break;
                    }
                }
                if(bamboo){
                    bamboos++;
                }
                else{
                    cycles++;
                }
            }
        }
        cout<<cycles + min(bamboos, 1) <<" "<<cycles + bamboos<<endl;
    }
}
