(1)1次元累積和

int N; cin >> N; // 配列サイズ
vector<int> a(N);
for (int i = 0; i < N; ++i) cin >> a[i]; // a の入力

// 累積和を実装する
vector<int> s(N+1, 0); // s[0] = 0 になる
for (int i = 0; i < N; ++i) s[i+1] = s[i] + a[i];

// 各クエリに答える
// 区間 [left, right) の総和を求める
int left, right;
cin >> left >> right;
cout << s[right] - s[left] << endl;


(2)２次元累積和
//s[x][y]:=[0,x)×[0,y)の長方形区間の和


int main() {
    // 入力: H × W のグリッド
    int H, W; 
    cin >> H >> W;
    vector<vector<int> > a(H, vector<int>(W));
    
    for (int i = 0; i < H; ++i) for (int j = 0; j < W; ++j) cin >> a[i][j];


    // 二次元累積和
    vector<vector<int> > s(H+1, vector<int>(W+1, 0));
    
    for (int i = 0; i < H; ++i)
        for (int j = 0; j < W; ++j)
            s[i+1][j+1] = s[i][j+1] + s[i+1][j] - s[i][j] + a[i][j];

    // クエリ [x1, x2) × [y1, y2) の長方形区域の和
    int Q; cin >> Q;
    for (int q = 0; q < Q; ++q) {
        int x1, x2, y1, y2;
        cin >> x1 >> x2 >> y1 >> y2;
        cout << s[x2][y2] - s[x1][y2] - s[x2][y1] + s[x1][y1] << endl;
    }


(3) imos法
いもす法(imos法)とは
...長さNの1次元配列において、「ある連続する区間に、ある数vを足す」という操作をK回繰り返した結果を
計算量O(N+K)で高速に構築できる方法である

// step1　加算処理
区間[l, r]に値vを加算したいとき
・・・l番目の値にvを加算して, "r+1"番目の値に-vを加算する

// step2 accumulation of sum
累積和を取ることで最終結果を得る

// ex.
vector<int> imos(1010101, 0);
   
   // imos method
   // ある区間[a, b] を追加するとき
   // imos[a]++, imos[b+1]--とする
   // 1-dimensional 0-dimensional imos method
   rep(i, n){
       int a, b;
       cin >> a >> b;
       
       imos[a]++;
       imos[b+1]--;
   }
 
   // accumulation of sum
   for (int i = 0; i <= 1000000; i++) imos[i+1] += imos[i]; //ぼくはこの+を忘れがち！！必ず+すること！！
   
   int ans = 0;
   
   for (int i = 0; i <= 1000000; i++) ans = max(ans, imos[i]);



