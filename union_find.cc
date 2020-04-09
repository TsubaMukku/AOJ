//UnionFind

できること
・グループ分けの管理ができる
・２つの要素の属するグループの併合ができる
・２つの要素が同じグループに属するか否かの判定を行うことができる


class UnionFind{
public:

    //親の番号を格納する. Parentだった場合は−(the size)とする
    vector<int> Parent;
    
    //作るときはParentの値を全て-1にする
    //こうすると, すべての頂点が根となる
    UnionFind(int N){
        Parent = vector<int>(N, -1);
    }
    
    //Aがどのグループに属しているか調べる
    int root(int A){
        if (Parent[A] < 0) return A; //自分のグループにいる
        return Parent[A] = root(Parent[A]); //親をつなぎ替える
    }
    
    //size関数を作る
    //自分の所属するグループの頂点数を調べる
    long long size(int A){
        return -Parent[root(A)]; //親をとりたい
    }
    
    //AとBをくっつける
    bool connect(int A, int B){
        //AとBを直接繋がない
        //root(A) に root(B)をくっつける　
        //リーダー同士をくっつける
        
        A = root(A);
        B = root(B);
        
        if (A == B){
            return false; //すでにくっついてる
        }
            
        //大きい方に小さい方をくっつけたい
        //大小が逆だったらひっくり返す
            
        if(size(A) < size(B)) swap(A, B);
        
        //Aのサイズを更新する
        Parent[A] += Parent[B];
        
        //BのParentをAに変更する
        Parent[B] = A;
        
        return true; //くっついた
    }
    
};












