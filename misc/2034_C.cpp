#include <bits/stdc++.h>

using namespace std;

void run(){
    int n, m;
    cin>>n;
    cin>>m;
    string maze[n+1];
    for(int i = 1; i<=n; i++){
        cin>>maze[i];
        maze[i] = "-" + maze[i];
    }
    // vector<int> curr_vis;
    // string visit_maze[n+1];
    // copy(begin(maze), end(maze), begin(visit_maze));
    // std::copy(maze->begin(), maze->end(), maze->begin());
    // std::fill(visit_maze->begin(),visit_maze->end(),"")
    // for(int i = 1; i<=n; i++){
    //     for(int j = 1; j<=m; j++){
    //         if(visit_maze)
    //     }
    // }
    vector<pair<int,int>> jda[n+2][m+2];
    for(int i =1; i<=n; i++){
        for(int j =1; j<=m; j++){
            if(maze[i][j]=='U') jda[i-1][j].push_back({i, j});
            if(maze[i][j]=='D') jda[i+1][j].push_back({i, j});
            if(maze[i][j]=='L') jda[i][j-1].push_back({i, j});
            if(maze[i][j]=='R') jda[i][j+1].push_back({i, j});
        }
    }

    int vis[n+2][m+2] = {};
    queue<pair<int,int>> q;
    for(int j = 0; j <= m+1; j++) vis[0][j] = 1, q.push({0,j});
    for(int i = 0; i <= n+1; i++) vis[i][0] = 1, q.push({i,0});
    for(int j = 1 ; j <= m+1 ; j++) vis[n+1][j] = 1 , q.push({n+1 , j});
    for(int i = 1 ; i <= n ; i++) vis[i][m+1] = 1 , q.push({i , m+1});

    while(q.size()){
        pair<int,int> temp = q.front();
        q.pop();
        for(auto [a,b] : jda[temp.first][temp.second]){
            if(vis[a][b]!=1){
                vis[a][b] = 1;
                q.push({a,b});
            }
        }
    }

    for(int i = 1 ; i <= n ; i++){
            for(int j = 1 ; j <= m ; j++){
                if(maze[i][j] == '?' and
                vis[i-1][j] and vis[i][j+1] and vis[i+1][j] and vis[i][j-1]) vis[i][j] = 1;
            }
        }
        int ans = n * m;
        for(int i = 1 ; i <= n ; i++){
            for(int j = 1 ; j <= m ; j++){
                if(vis[i][j] == 1) ans -= 1;
            }
        }
        cout << ans << endl;

}

int main(){
    int t;
    cin>>t;

    while(t--){
        run();
    }
}