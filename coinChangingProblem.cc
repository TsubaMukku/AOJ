/*
例えばですが, 

Sample Input 2
15 6
1 2 7 8 12 50

を題材に, 次のように考えてみてはいかがでしょうか.
（「合理的に考えると自然に動的計画法にたどり着く（たどり着かざるを得ない）」説明になっていたら幸いです.

１　まずはDPを知らない頃の気持ちになって考えましょう. もし入試とかでこの問題が出たら, どう考えるでしょうか？？？


２　解法の一つに, このようなアイデアが浮かびませんか？？

（１）今回の場合, １５円を支払うために, 6種類のコインを使うことができる. しかも, 同じコインを何度も使える.

（２）
この表を見てください（すでに書き込んでいますが, 書き込みがなかった状態を想定してください）
表：https://docs.google.com/spreadsheets/d/1R7SqBD-2g1KlAw6L3uHB7xP7YEqys8dgW89caBjPuN8/edit?usp=sharing


１円コインだけを使ったとき, 1円~15円を支払うためには, １円コインはそれぞれ最低何枚必要なのかを表で埋めます. 
２円コインだけを使ったとき, 1円~15円を支払うためには, １円コインはそれぞれ最低何枚必要なのかを表で埋めます. それが不可能な場合は「無理」と書き込みます.
他のコインについても同様の作業を行い, 表を一旦完成させます. （ただし, 一番下の最小で何枚？？の項目は, まだ埋められません）

（３）
完成させた表をもとに, 最小で何枚？？の項目を埋めてみます.（ごめんなさい. 私の力不足で, ここを上手く言語化できませんでした）

そのとき, 無意識のうちに, 「そこまででわかっている結果を, 次の状態の計算結果を求める際に使っている」ことに気が付きませんか？？
例えば, 「８円を支払うために最小で何枚必要か, すでに確定している」（そこまででわかっている結果）ことを踏まえて, 

・９円支払うには最小何枚か？ 
・１１円支払うには最小何枚か？
・１５円支払うには最小何枚必要か？

と考えていませんか？？？？

このときの無意識の発想, つまり「途中までの結果を記録しておいて, その後の作業で有効活用する」という発想, 
これこそが動的計画法のアイデアだと思いませんか？？


これは〇〇問題だから動的計画法！！,,って理解するより, 問題をしっかり解きほぐすと,
「ある状態までの計算結果（なにかの結果）を記録しておいて、次以降の操作で使う」というアイデアが解法に繋がる場合, 
それを実装したものこそが動的計画法, と言えるのではないでしょうか？？？

*/

// 上記の内容を踏まえて, 以下に, 実装例を示します:

#include <iostream>
#include <algorithm>

using namespace std;
 
const int INF = 1e9; // 「無理」という状態に対応します
 
int main() {
    int n, m;
    int c[22];
 
    cin >> n >> m;
 
    for (int i = 0; i < m; i++) {
        cin >> c[i];
    }
 
    int dp[50005]; //x円支払うために必要なコインの最小枚数をdp[x]に記録します
    
    // dpテーブルを初期化します
    for (int i = 0; i < 50005; i++) {
        if (i == 0) dp[i] = 0; // 0円を支払うためにコインは必要ありません（0枚必要です)
        else dp[i] = INF;
    }
 
    for (int i = 0; i <= 50000; i++) {
        for (int j = 0; j < m; j++) {
            if ( i + c[j] > 50000 ) continue; // 制約の上限より大きい値は見る必要がありません
            dp[i+c[j]] = min(dp[i] + 1, dp[i+c[j]]); //表で一番下「最小で何枚？？」の項目を作るときの操作を思い出してください
        }
    }
    cout << dp[n] << endl; // n円支払うときのコインの最小枚数はdp[n]に格納されています
 
    return 0;
}

/*
TLでのコメントから, 「DPは慣れ」とか「精進」とかではなく, 「どうしてそう考えるの？？？」という説明を期待なさっているのかなと思いました.
精神論ではなく, 合理的に考えることで, この問題で学べるポイントを, いろんな問題に一般化していただけると幸いです.
「なぜ？？？」という疑問の解消につながりましたかね？？？
*/
        for (int j = 0; j < m; j++) {つ
        for (int j = 0; j < m; j++) {
