#include <iostream>
#include <vector>

using namespace std;

const long long INF = 1LL<<60;

/*
街がn個ある. 街0からスタートすると仮定する（１点をfixしないと考えられない）
dp[最後に訪れた街がi][S : 通った街の集合]を計算する
答えは, 全部の街を通ったときのpathの総和の最小値　+ 街iから街0へ戻るpathの重み
loopでn-1個をチェックして, 最短距離を求める
その最短距離がTSPの答えである
*/

/*
c[最後に訪れた街がi][S : 通った街の集合]:
街iを最後に訪れたとき, それまでのpathの総和の最小値と定義する
*/

int main(){
    int n, e;
    cin >> n >> e;
    
    vector<vector<long long>> dist(n+1, vector<long long>(n+1, INF));
    
    for (int i = 0; i < e; i++){
        int s, t, d;
        cin >> s >> t >> d;
        
        dist[s][t] = d;
    }
    
    vector<vector<long long>> c(n+1, vector<long long>(1<<n, INF));
    
    c[0][1] = 0; // 動いていないからpath weight 0
    
    // 集合Sにより状態を管理する
    // bit が１であることは, already visitedを意味する
    // bit が0であることは, not visitedを意味する
    
    for (int s = 0; s < (1<<n); s++){
        
        // start
        for (int from =  0; from < n; from++){
            
            // end
            for (int to = 0; to < n; to++){
                
                // if i \notin S
                // not visited yet
                if(!(s & (1<<from))) continue;
                
                // if j \in S
                // already visited
                if (s & (1<<to)) continue;
                
                if (c[to][s | (1<<to)] > c[from][s] + dist[from][to]){
                    c[to][s | (1<<to)] = c[from][s] + dist[from][to];
                }
            }
        }
    }
    
    
    long long ans = INF;
    
    // loopでn-1個をチェックしてTSPの最短距離を求める
    for (int i = 1; i < n; i++){
        ans = min(ans, c[i][(1<<n)-1] + dist[i][0]);
    }
    
    // if ans == INF, there exists no path for a traveling salesman 
    if (ans == INF) cout << -1 << endl;
    else cout << ans << endl;
}

/ *
使ったビット演算テクニック
(1)ビット S に i 番目のフラグが立っているかどうか
if (S & (1<<i))　　: i \in S かどうかを表す

(2)ビット S に i 番目のフラグが消えているかどうか
if (!(S & (1<<i)))  : i \notin Sかどうかを表す

(3)ビット S に i 番目のフラグを立てたもの
S｜(1<<i)	 : S \cup {i}を表す
*/
