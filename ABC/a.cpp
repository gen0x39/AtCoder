#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
const ll INF = 1LL << 60;

int main(void){
    int H, W; cin >> H >> W;
    vector<string> maze(H);
    rep(i,H) cin >> maze[i];

    int sx,sy;
    int gx,gy;

    // スタートとゴール
    rep(i,H) rep(j,W) {
        if(maze[i][j] == 'S'){
            sx = i; sy = j;
        }
        if(maze[i][j] == 'G') {
            gx = i; gy = j;
        }
    }

    // 上下左右
    int dx[4] = { 0, 0,-1, 1};
    int dy[4] = { 1,-1, 0, 0};

    // キュー
    P s; s.first = sx; s.second = sy;
    queue<P> que;
    int ans = 0;
    
    rep(i,H) rep(j,W) {
        if((i==sx && j == sy) || (i==gx && j == gy)) continue;
        char tmp = maze[i][j];
        maze[i][j] = '.';
        que.push(s);

        while (!que.empty()){
            rep(i,4) {

            }
        }
        

        // デバック
        /*
        cout << "---------" << endl;
        rep(i,H) cout << maze[i] << endl;
        cout << "---------" << endl;
        */
        maze[i][j] = tmp;

    }
    
    return 0;
}
