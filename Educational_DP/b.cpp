#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
const ll INF = 1LL << 60;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

int main(void){
    int n, k;
    cin >> n >> k;
    vector<int> h(110000);
    rep(i,n) cin >> h[i];

    ll dp[110000];
    rep(i,n) dp[i] = INF;

    dp[0] = 0;

    for(int i = 0; i < n; ++i){
        for(int j = 1; j <= k; ++j){
            chmin(dp[i + j], dp[i] + abs(h[i] - h[i + j]));
        }
    }

    cout << dp[n-1] << endl;

    return 0;
}
