#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(void){
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i,n) a[i] = i+1;

    map<vector<int>, int> mp;
    do {
        rep(i,n) cout << a[i] << ' ';
        putchar('\n');
    }while(next_permutation(a.begin(),a.end()));
    
    return 0;
}
