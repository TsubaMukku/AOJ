#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/*

BIT: 区間和の更新や計算を行う構造体である.
初期値はすべて０である.

method:
sum(i): a_1 + a_2 + ... + a_iを計算して返す
add(i,x): a_i にxを加算する
時間計算量は sum, addともに O(log n)である.
*/

template <typename T>
struct BIT {
    
    int n;
    vector<T> bit;
    
    BIT(int n_): n(n_ + 1), bit(n,0) {}
    
    T sum(int i){
        T s(0);
        while (i > 0){
            s += bit[i];
            i -= (i & -i);
        }
        return s;
    }
    
    void add(int i, T x){
        while (i <= n){
            bit[i] += x;
            i += (i & -i);
        }
    }
    
};

int main(void){
   
   int n, q;
   cin >> n >> q;
   BIT<int> bit(n);
   
   for (int i = 0; i < q; i++){
       int com, x, y;
       cin >> com >> x >> y;
       
       if (com == 0){
           bit.add(x,y);
       }
       else{
           cout << bit.sum(y) - bit.sum(x-1) << endl;
       }
   }
}
