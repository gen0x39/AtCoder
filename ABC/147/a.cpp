#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
const ll INF = 1LL << 60;

int main(void){
    int a1, a2, a3;
    cin >> a1 >> a2 >> a3;
    if(a1+a2+a3 >= 22) cout << "bust" << endl;
    else cout << "win" << endl;    
    return 0;
}
