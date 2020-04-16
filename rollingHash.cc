// https://onlinejudge.u-aizu.ac.jp/problems/ALDS1_14_B
// AOJ ALDS_14_B

#include <iostream>
#include <vector>
#include <string>

using namespace std;
using ll = long long;

// ローリングハッシュ
// h = 2^64にすることでmod不要となる（オーバーフローしたら値が範囲内に戻る）
using ull = unsigned long long;

// sの中からtと一致する部分の各出現位置を返す関数である
vector<ll> rollingHash(string s, string t){
    
    vector<ll> index_list; //この配列に答えとなるindexたちを記録する
    
    ll SL = s.size();
    ll TL = t.size();
    
    ull b = 1e9 + 7; // hashの基数である

    // 蟻本でいう、bのm乗
    ull a = 1;
    for (int i = 0; i < TL; i++) a *= b;
    
    // sの最初のTL文字に関するハッシュ値を計算する
    ull sH = 0;
    for (int i = 0; i < TL; i++) sH = sH * b + s[i];
    
    // tの最初のTL文字に関するハッシュ値を計算する
    ull tH = 0;
    for (int i = 0; i < TL; i++) tH = tH * b + t[i];

    // sの始点を1つずつ進めながらハッシュ値をチェック
    for (int i = 0; i +TL <= SL; i++){ 
        
        if (sH == tH) index_list.push_back(i); //ハッシュ値が一致することを, Tの中にPと一致する箇所があることとみなす
        
        if (i + TL < SL) sH = sH*b + s[i+TL] - s[i] * a; // ハッシュ値の累積和を考えている
    }

    return index_list;
}

int main(){

    // input
    string s, t;
    cin >> s >> t;

    auto ans = rollingHash(s, t); //この配列に答えとなるindexたちをansへ保持する
    
    for(ll i : ans){
        cout << i << endl; //indexの値が小さい順に出力される
    }

    return 0;
}
