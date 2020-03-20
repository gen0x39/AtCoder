# AtCoder緑に向けて

AtCoder緑になるまでに要求される知識の内容を例題コードも含めて列挙した.  

参考  
- [AtCoder緑になるまでにやったこと、必要な知識](https://qiita.com/aki-takano/items/3b3e8c4e10920c1a755a)
- [AtCoder 版！蟻本 (初級編)](https://qiita.com/drken/items/e77685614f3c6bf86f44)

## 時間計算量の話

AtCoderでTLEにならない時間計算量について

[計算量オーダーの求め方を総整理！ 〜 どこから log が出て来るか 〜](https://qiita.com/drken/items/872ebc3a2b5caaa4a0d0)

> | ループ回数 |              蟻本の記載              |                 現在                 |
> | :--------: | :----------------------------------: | :----------------------------------: |
> |   $10^6$   |         余裕を持って間に合う         |                  -                   |
> |   $10^7$   |           おそらく間に合う           |         余裕を持って間に合う         |
> |   $10^8$   |   非常にシンプルな実装でない限り厳しい  |           おそらく間に合う           |
> |   $10^9$   |                 -                 | 非常にシンプルな実装でない限り厳しい |

## bit全探索

[bit 全探索](https://drken1215.hatenablog.com/entry/2019/12/14/171657)

N個の要素からなる集合$\{0,1,,...,N-1\}$の部分集合を調べ上げる手法のこと。  
累積和はある範囲の総和を調べる手法だが、これは部分集合を調べるので順序に関係しない問題を扱えそう??  
bit全探索の典型問題である部分和問題を解いてみる。

**部分和問題**

N個の整数$a_0,a_1...,a_{N-1}$と正の整数$W$とが与えられる。  
$a_0,a_1...,a_{N-1}$の中から何個か選んで総和を$W$とすることができるか？

**制約**

$1 \leq N \leq 20$

**解法**

$N$が小さいので全探索$(2^N \sim 10^6)$できる。  
選んだ総和がWに一致するものがあるかどうかを判定する。

**サンプルコード**

```c++
#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;

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
        
        // 範囲ベースforループ
        // http://vivi.dyndns.org/tech/cpp/range-for.html
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
```

例題
- [ABC147 C](https://atcoder.jp/contests/abc147/tasks/abc147_c) 令和ABCのC問で一番難しい問題らしい

## 二分探索

テンプレ

簡単な概要

計算量

適応可能な問題

問題例

Atcoder 128 C



証明

実装

## 優先度付きキュー

> 次のような操作が行えるデータ構造をプライオリティキュー（優先度付きキュー）と呼びます。
>
> - 数を追加する。
> - 最小の数値を取り出す（値を取得し、削除する）。
>
> 蟻本p.69より抜粋

最小値の取り出しを $O(1)$ でできるので、数列をなめていきながら最小値（最大値）が欲しいときに使える。

例題

- [POJ 2431 - Expedition](https://eagletmt.github.io/contests/blog/poj-2431/)
- [PKU 3253 - Fence Repair](http://algoogle.hadrori.jp/pku/3253/)

## 簡単なDFSとBFS

[迷路は幅優先探索？](https://qiita.com/nati-ueno/items/a789095aff0aec10d5d0) 視覚的にわかりやすい



### DFS



### BFS

[BFS (幅優先探索) 超入門！ 〜 キューを鮮やかに使いこなす 〜](https://qiita.com/drken/items/996d80bcae64649a6580)

BFSは探索の始点となる頂点から、各頂点の最短経路を求めることのできるアルゴリズム。

ただし、条件として各辺に重みのないグラフ（または各辺の重みが全て等しい）であることに限定される。

例題

- [ABC 007](https://atcoder.jp/contests/abc007/tasks/abc007_3) 迷路、BFSの基本



## 簡単なDP



例題

- [Educational DP Contest / DP まとめコンテスト](https://atcoder.jp/contests/dp)

## 素数判定

エラトステネスの篩を使って、



## 素因数分解



## 累積和

[累積和を何も考えずに書けるようにする！](https://qiita.com/drken/items/56a6b68edef8fc605821)

長さNの配列に対してある範囲 [left, right) の総和を前処理を行うことにより$O(1)$で求めることができる手法。

前処理

配列$a_0,a_1, ..., a_{N-1}$に対して、

配列$s_0,s_1,....,s_{N-1},s_N$を以下のように定める。

- $s_0 = 0$
- $s_1 = a_0$
- $s_1 = a_0 + a_1$
- $s_2 = a_0 + a_1 + a_2$
- ...
- $s_N = a_0 + a_1 + a_2 + ... + a_{N-1}$

これにより $a$ の区間 [4, 13)  の総和

- $a_4 + a_5 + a_6 + a_7 + a_8 + a_9 + a_{10} + a_{11} + a_{12}$

は、

- $s_{13} - s_4$

となるから $O(1)$ で求められる。ここで上式を見ると、

- $s_0 = 0, s_i = s_{i-1} + a_i   (i = 1,2,...,N )$

という関係がある。これは $O(N)$ で実装できる。



**しゃくとり法との相違点**

しゃくとり法が使えるのは配列の任意の要素が正のときに限定されるが累積和は正負が混合されていても適用可能。

例題

- [AGC023 A](https://atcoder.jp/contests/agc023/tasks/agc023_a)

## しゃくとり法

- [しゃくとり法 (尺取り法) の解説と、それを用いる問題のまとめ](https://qiita.com/drken/items/ecd1a472d3a0e7db8dce)

適応可能な問題

問題例

計算量

実装

## GCDとLCM