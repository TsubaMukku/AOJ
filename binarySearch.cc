// cf https://qiita.com/drken/items/97e37dd6143e33a64c8c
//めぐる式


// index が条件を満たすかどうか
bool isOK(int index, int key, vector<int> &a) {
    if (a[index] >= key) return true;
    else return false;
}

// 汎用的な二分探索のテンプレ
int binary_search(int key, vector<int> &a) {

    int ng = -1; //「index = 0」が条件を満たすこともあるから初期値は -1とする.
    int ok = (int)a.size(); // 「index = a.size()-1」が条件を満たさないこともあるため, 初期値は a.size()とする.

    /* ok と ng のどちらが大きいかわからないことを考慮する */
    /* どんな二分探索でもここの書き方を変えずにできる！ */
    while (abs(ok - ng) > 1) {
        int mid = (ok + ng) / 2;

        if (isOK(mid, key, a)) ok = mid;
        else ng = mid;
    }
    
    /* ng は条件を満たさない最大の値(index)
    ok は条件を満たす最小の値(index)になっている */
    return ok;
}
