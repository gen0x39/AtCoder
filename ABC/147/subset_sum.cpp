#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

// int型をvector型に変換
// bit: 集合を表す整数
// N: 何個のものについて考えているか
vector<int> IntegerToVector(int bit, int N) {
    vector<int> S;
    for (int i = 0; i < N; ++i) {
        if (bit & (1 << i)) {
            S.push_back(i);
        }
    }
    return S;
}

int main(void){
    // 入力
    int N, W;
    cin >> N >> W;
    vector<int> a(N);
    for(int i = 0; i < N; i++) cin >> a[i];

    // bit全探索
    bool exist = false;
    for(int bit = 0; bit < (1 << N); bit++) {
        // どれを選ぶか
        vector<int> S = IntegerToVector(bit, N);

        // 部分集合に対応する総和
        int sum = 0;
        for(int i : S) sum += a[i];

        // 判定
        if(sum == W) {
            exist = true;
            for(int i : S) cout << a[i] << " ";
            cout << endl;
        }
    }

    if (exist) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}
