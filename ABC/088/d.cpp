#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
const ll INF = 1LL << 60;

int main(void){
    // input
    int H, W; cin >> H >> W;
    vector<string> maze(H);
    rep(i,H) cin >> maze[i];

    // initialization
    int sx = 0, sy = 0;
    int gx = H-1, gy = W-1;
    P p; p.first = sx; p.second = sy;
    queue<P> que;
    que.push(p);

    // 上下左右
    int dx[4] = { 0, 0,-1,+1};
    int dy[4] = {+1,-1, 0, 0};

    // 距離を管理
    // 中身を-1で初期化
    vector<vector<int> > dist(52, vector<int>(52, -1));
    dist[sx][sy] = 0;
    int count = 0;
    rep(i,H){
        rep(j,W) if(maze[i][j] == '#' )count++ ;
    }

    while(!que.empty()){
        P v = que.front();
        que.pop();
        
        if(v.first == gx && v.second == gy) break;

        rep(i,4) {
            int nx = v.first + dx[i];
            int ny = v.second + dy[i];
            if (nx < 0 || ny < 0 || nx >= H || ny >= W) continue;
            if (maze[nx][ny] == '#') continue;
            if (dist[nx][ny] != -1) continue;
            dist[nx][ny] = dist[v.first][v.second] + 1;
            P p; p.first = nx; p.second = ny;
            que.push(p);
        }
    }

    // 到達不可能
    if (dist[H-1][W-1] == -1) {
        cout << "-1" << endl;
        return 0;
    }

    cout << H * W - dist[H-1][W-1] - count - 1  << endl;

    return 0;
}
