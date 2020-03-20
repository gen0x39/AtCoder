#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
const ll INF = 1LL << 60;

int main(void){
    // input
    // r:行, c:列
    int r, c; cin >> r >> c;
    int sx, sy; cin >> sx >> sy;
    int gx, gy; cin >> gx >> gy;
    --sx; --sy; --gx; --gy;

    // 迷路
    vector<string> maze(r);
    rep(i,r) cin >> maze[i];

    // 距離
    vector<vector<int> > dist(52, vector<int>(52, -1));
    dist[sx][sy] = 0;

    // xy座標の管理
    queue<P> que;
    P P1;
    P1.first = sx; P1.second = sy;
    que.push(P1);

    // 上下左右
    int dx[4] = { 0, 0,-1, 1};
    int dy[4] = { 1,-1, 0, 0};

    while (!que.empty()) {
        P v = que.front();
        que.pop();
        
        if(v.first == gx && v.second == gy) break;

        rep(i,4) {
            int nx = v.first + dx[i];
            int ny = v.second + dy[i];

            // 迷路の範囲外
            if (nx < 0 || r <= nx || ny < 0 || c < ny) continue;
            // 壁
            if (maze[nx][ny] == '#') continue;
            // 距離計算済み
            if (dist[nx][ny] != -1) continue;

            dist[nx][ny] = dist[v.first][v.second] + 1;
            P p;
            p.first = nx; p.second = ny;
            que.push(p);
        }
    }
    cout << dist[gx][gy] << endl;
    //　確認用
    /*
    rep(i, r){
        rep(j, c){
            cout << dist[i][j] << " ";
        }
        cout << endl;
    }
    */
    return 0;
}