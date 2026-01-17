#include <bits/stdc++.h>

using namespace std;

struct State{
    int r, c, dir, count;
};

int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

int dist[200005][4][4];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m;
    cin>>n>>m;

    vector<string> maze(n);

    int sr, sc, tr, tc;
    for(int i = 0; i<n; i++){
        cin>>maze[i];
        for(int j = 0; j < m; j++){
            if(maze[i][j]=='S'){
                sr = i; sc = j;
            }
            else if(maze[i][j]=='T'){
                tr = i; tc = j;
            }
        }
    }

    for (int i = 0; i < n * m; ++i)
        for (int d = 0; d < 4; ++d)
            for (int k = 0; k < 4; ++k)
                dist[i][d][k] = -1;

    queue<State> q;

    // initial val in q
    for(int d = 0; d<4; d++){
        int nr = sr + dr[d];
        int nc = sc + dc[d];
        if (nr >= 0 && nr < n && nc >= 0 && nc < m && maze[nr][nc] != '#') {
            dist[nr * m + nc][d][1] = 1;
            q.push({nr, nc, d, 1});
        }
    }

    while(!q.empty()){
        State curr = q.front();
        q.pop();

        if (curr.r == tr && curr.c == tc) {
            cout << dist[curr.r * m + curr.c][curr.dir][curr.count] << endl;
            return 0;
        }

        int current_dist = dist[curr.r * m + curr.c][curr.dir][curr.count];

        // Try all 4 directions
        for (int d = 0; d < 4; ++d) {
            int nr = curr.r + dr[d];
            int nc = curr.c + dc[d];

            // Check boundaries and walls
            if (nr < 0 || nr >= n || nc < 0 || nc >= m || maze[nr][nc] == '#') 
                continue;

            int next_count = (d == curr.dir) ? curr.count + 1 : 1;

            // Rule: cannot exceed 3 steps in the same direction
            if (next_count <= 3) {
                if (dist[nr * m + nc][d][next_count] == -1) {
                    dist[nr * m + nc][d][next_count] = current_dist + 1;
                    q.push({nr, nc, d, next_count});
                }
            }
        }

    }

    cout<<-1<<endl;
}