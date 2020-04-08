#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const long long INF = 1e+9;
const long long MAX_V = 100000;


struct edge {
    long long to;
    long long cost;
};

// <最短距離, 頂点の番号>
using P = pair<long long, long long>;

long long V;
vector<edge> G[MAX_V]; // 隣接行列

void Dijkstra(long long s, vector<long long> &d) {
    
    // 最短距離が小さい順番に取り出す
    // 始点の情報とそこへの最短距離（始点なら $0$ ）をpushする
    priority_queue<P, vector<P>, greater<P> > que;
    
    d[s] = 0; // 始点ｓから頂点sへの最短経路の長さは0である
    
    que.push(P(0, s));
    
    
    while (!que.empty()) {
        
        P p = que.top(); // キューの先頭要素（最短距離の一番小さいもの）を取り出す。
        que.pop();
        
        long long v = p.second;
        
        
        //記録済み最短距離より, 取り出した要素に入っている距離情報のほうが大きい場合
        // ここで打ち切って先頭要素を取り出す操作に戻る
        
        if (d[v] < p.first) continue;  // ??????????
        
        // 移動できる頂点を走査する
        for (int i=0; i<G[v].size(); ++i) {
            
            edge e = G[v][i];
            
            // 最短距離が更新できるものがあれば、距離を更新する
            if (d[e.to] > d[v] + e.cost) {
                
                d[e.to] = d[v] + e.cost;
                que.push(P(d[e.to], e.to)); // 頂点への距離、頂点の情報をキューにpushする
            }
            
        }
        
    }
    
}  
    
  int main(){
    
    cin >> V;
    long long E;
    cin >> E;
    
    long long r;
    cin >> r;
    
    for (int i = 0; i < E; i++){
        
        long long a, b, c;
        cin >> a >> b >> c;
        
        edge e = {b, c};
        G[a].push_back(e);
    }
    
    vector<long long> d(MAX_V, INF);
    
    Dijkstra(r,d);
    
    for (int i = 0; i < V; i++){
        if (d[i] != INF) cout << d[i] << endl;
        else cout << "INF" << endl;
    }
    
    return 0;
}

// 計算量は $O(E\log V)$ である
  
    
