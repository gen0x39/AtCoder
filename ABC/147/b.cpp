#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
const ll INF = 1LL << 60;

int main(void){
    string s;
    cin >> s;
    int n = s.length();
    int ans = 0;
    for(int i = 0; i < n/2; i++){
        if (s[i]!=s[n-1-i]) ans++;
    }
    cout << ans << endl;
    return 0;
}
