// https://qiita.com/nomikura/items/1518bc8a6e04d2580b0d


// 盤面の状態を記録する
vector<vector<char>> grid(H, vector<char>(W));


// 盤面を評価する関数である
int value() {
    // 中身を書く
}

int MIN_MAX(int turn) {
    // 終局したら盤面の値を返す
    if (turn == END) return value();

    if (/*自分の局面*/) {
        int Max = -INF;
        for () {
            // 今の盤面で自分が打てるすべての状態を列挙
            Max = max(Max, MIN_MAX(turn + 1));
        }
        return Max;
    } else { // 相手の局面
        int Min = INF;
        for () {
            // 今の盤面で相手が打てるすべての状態を列挙
            Min = min(Min, MIN_MAX(turn + 1));
        }
        return Min;
    }
}


int main() {
    // こんな感じで呼び出せば自分の得点の最大値を知ることができる。
    int myPoint = MIN_MAX(0);
}
