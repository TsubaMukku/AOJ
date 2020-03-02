/**
 * Tsubasa　Takamuku
 * 2020/03/02 Revised
 * 
 */

**********partitionは何を行う関数か？？？？***

partiton(a, p, r)
  -> a[p,,,,q-1]の各要素が a[q]以下, a[q+1,,,r]の各要素がa[q]より大きい, となるようにaを２つに分割する関数である
  -> index q を戻り値として返す
******************************************



int a[1010101], n;
int func(int p, int r){
    int x, i, j, t;
    
    //partitionの対象範囲はp~rである
    //partitionの基準となる要素はa[r]である
    x = a[r];
    i = p-1;
    
    for (j = p; j < r; j++){
        
        //a[j] > xのときは要素移動なし
        //a[j]をxより大きいグループに含める
        
        //a[j] <= xのときは要素移動が起こる
        if (a[j] <= x){
            
            //基準となるx以下の要素は, [p, i]に存在しなければならない
            i++;
            t = a[i];
            a[i] = a[j];
            a[j] = t;
        }
    }
    
    
    //末尾の要素については, 個別に考える必要がある
    i++;
    t = a[i];
    a[i] = a[r];
    a[r] = t;
    
    
    return i;
}

