#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define mt make_tuple
#define fi first
#define se second
#define all(a) (a).begin(),(a).end()
#define endl "\n"
#define rep(i, a, b) for (auto (i) = (a); (i) < (b); (i)++)
#define rrep(i, a, b) for (auto (i) = (a); (i) > (b); (i)--)
#define UNIQUE(v) (v).erase(unique((v).begin(), (v).end()), (v).end());
#define BEGIN_SOLVER class solver{public:
#define END_SOLVER };

#ifdef LOCAL_DEFINE
struct InitInput{
  InitInput() {
    FILE *stream1;
    stream1 = freopen("/Users/aim_cpo/CLionProjects/competitive/in.txt", "r", stdin);
    assert(stream1 != nullptr);
    cerr << "This problem is not interactive" << endl;
  }
}LOCAL_INPUT;
struct LOCAL_OUTPUT{
  LOCAL_OUTPUT() {
    FILE *stream2;
    const char *outputfile = "out.txt";
    stream2 = freopen(outputfile, "w", stdout);
    assert(stream2 != nullptr);
    cerr << "output [ " << outputfile << " ]" << endl;
  }
}/*LOCAL_OUTPUT*/;
#define show(x) cerr << #x << " = " << (x) << " (line " << __LINE__ << ")" << endl
#define showV(v, n) do{\
for(int _i_t_e_=0; _i_t_e_<(n);_i_t_e_++)\
cerr<<"("<<_i_t_e_<<" = "<<(v)[_i_t_e_]<<") ";\
cerr<<endl;}while(0)
#define showA(a, n) do{\
for(int _i_t_e_=0;_i_t_e_<(n);_i_t_e_++)\
cerr<<"("<<_i_t_e_<<" = "<<(a)[_i_t_e_]<<") ";\
cerr<<endl;}while(0)
#define showA2(a, n, m) do{\
for(int _i_t_e_=0;_i_t_e_<(n);_i_t_e_++){\
for(int _i_t_e_2=0;_i_t_e_2<(m);_i_t_e_2++){\
cerr<<"("<<_i_t_e_<<", "<<_i_t_e_2<<" = "<<(a)[_i_t_e_][_i_t_e_2]<<") ";\
}cerr<<endl;}cerr<<endl;}while(0)
#else
#define show(x)
#define showV(v, n)
#define showA(a, n)
#define showA2(a, n, m)
#endif

struct InitAim{
  InitAim() {
    ios::sync_with_stdio(false);cin.tie(nullptr);
    cout.precision(12);cout<<fixed;
#ifdef LOCAL_DEFINE
    cerr << "This problem is not interactive" << endl;
#endif
  }
}aim_cpo;

typedef long long ll;
typedef unsigned long long ull;

constexpr const int INT_INF=0x3f3f3f3f; //1061109567
constexpr const ll LL_INF=0x3f3f3f3f3f3f3f3f; //4557430888798830399

template <typename T> bool chmin(T &a, T b){return a>b?(a=b,true):false;}
template <typename T> bool chmax(T &a, T b){return a<b?(a=b,true):false;}
template <typename T> void ln(T i, T n){cout<<(i==n-1?"\n":" ");}
template<typename T, typename S>
ostream &operator<<(ostream &out, const pair<T, S> &pair1) {
  out << '(' << pair1.fi << ", " << pair1.se << ')';
  return out;
}
template<typename T>
ostream &operator<<(ostream &out, const vector<T> &vector1) {
  out << '[';
  for (unsigned int i = 0; i < vector1.size(); i++) {
    out << vector1[i];
    if (i == vector1.size() - 1)out << "]"; else out << ", ";
  }
  return out;
}

// INT
#define GCD(a, b) __gcd(a, b)
template <typename T> T LCM(T a, T b) {return a / GCD(a, b) * b;}
template <typename T> T EXTGCD(T a, T b, T& x, T& y) {
  T d = a;
  if (b != 0) {d=EXTGCD(b,a%b,y,x);y-=(a/b)*x;}
  else x=1,y=0;
  return d;
}
template <typename T> bool is_prime(T a) {
  for(int i=2;i*i<=a;i++)if(a%i==0)return true;
  return false;
}
template <typename T, typename S> T Pow(T a, S b) {
  T res = 1, now = a;
  while(b){if(b&1)res*=now;b>>=1;now*=now;}return res;
}

//// MOD
//ll MOD = 1000000000L + 7L;
//#define add(a, b) ((a % MOD) + (b % MOD)) % MOD
//#define mul(a, b) ((a % MOD) * (b % MOD)) % MOD
//#define sub(a, b) ((a % MOD) + MOD - (b % MOD)) % MOD
//template <typename T, typename S> T ModPow(T a, S b) {
//  assert(b >= 0);
//  T res = 1, now = a;
//  while(b){show(now);if(b&1)res=mul(res,now);b>>=1;now=mul(now,now);}return res;
//}
//template <typename T> T mod_inverse(T a, T mod, bool prime){ // if mod is prime, "prime" is true.
//  if(prime)return ModPow(a, mod - 2);
//  else{T x,y;EXTGCD(a,mod,x,y);return (mod+x%mod)%mod;}
//}
//#define divide(a, b) mul((a % MOD), (mod_inverse(b, MOD, true))) % MOD

/**
 * @file ModInt.cpp
 * @brief mod構造体
 * @author btk15049
 * @date 2019/03/08
 * @datails
 *  \todo verifyが足りない
 */

//! [WARNING!] mod が入力で与えられる場合はconstexprを外す
constexpr static int mod = 1e9+7;

/**
* @brief mod構造体
* @details 整数をラップして，常に保持されているデータがmodされた状態になるよう管理．
*/
class ModInt{
private:
  //! 中身
  int x;
public:
  /**
  * @brief ゲッター
  * @details 出力時などは "cout << *ret << endl;"のようにやるとよい．
  */
  long long operator*()const{
    return x;
  }
  ModInt(){
    x=0;
  }

  /**
  * @brief intからのコンストラクタ
  * @param[in] y 設定したい値
  * @details modをとらないので高速．ただしmodより大きい値や負の数を入れると事故るので注意．
  */
  ModInt(const int y){
    x=y;
  }

  /**
  * @brief long longからのコンストラクタ
  * @param[in] y 設定したい値
  * @details 毎回modを取るので低速．
  */
  ModInt(const long long y){
    x=(int)((mod+y%mod)%mod);
  }

  /**
  * @brief 整数から高速にModIntを作りたいときに使う
  * @param[in] x 設定したい値
  * @details xが[0,mod)であることが保証されてないと正しく動かない．
  */
  static inline ModInt raw(const long long x){
    //assert(x<mod);
    return ModInt((int)x);
  }

  /**
  * @brief 整数から安全にModIntを作りたいときに使う
  * @param[in] x 設定したい値
  * @details mod2回取るから遅い．負数でもOK．
  */
  static inline ModInt get(const long long x){
    return ModInt(x);
  }

  /**
  * @brief intからの代入演算子
  * @param[in] o 設定したい値
  * @details modをとらないので高速．ただしmodより大きい値や負の数を入れると事故るので注意．
  */
  ModInt& operator=(const int o){
    this->x=o>=mod?o-mod:o;
    return *this;
  }

  /**
  * @brief long longからの代入演算子
  * @param[in] o 設定したい値
  * @details mod2回取るから遅い．負数でもOK．
  */
  ModInt& operator=(const long long o){
    this->x=(int)((mod+o%mod)%mod);
    return *this;
  }
};

/**
* @param[in] l ModInt
* @param[in] r ModInt
* @details if文使って少し高速化．
*/
inline ModInt add(const ModInt l,const ModInt r){
  const long long x = *l+*r;
  return ModInt::raw(x>=mod?x-mod:x);
}

/**
* @param[in] l ModInt
* @param[in] r ModInt．
*/
inline ModInt mul(const ModInt l,const ModInt r){
  return ModInt::raw(*l**r%mod);
}

/**
* @brief a^x %modを求める
* @param[in] a ModInt
* @param[in] x long long．
*/
inline ModInt pow(ModInt a, long long x){
  ModInt ret=ModInt::raw(1);
  while(x){
    if(x&1){
      ret=mul(ret,a);
    }
    a=mul(a,a);
    x>>=1;
  }
  return ret;
}

/**
* @brief x^-1 %modを求める
* @param[in] x ModInt．
* @details
*   内部ではユークリッドの拡張互助法を使っている．
*   O(log(mod))
*/
inline ModInt inv(const ModInt x){
  long long a = *x, b = mod, u = 1, v = 0;
  while (b) {
    long long t = a / b;
    swap(a -= t * b, b);
    swap(u -= t * v, v);
  }
  return ModInt::get(u);
}

/**
* @brief 負数を求める単項演算子
* @param[in] x ModInt
*/
inline ModInt operator-(const ModInt x){
  return add(mod, -*x);
}

/**
* @param[in] l ModInt
* @param[in] r ModInt
*/
inline ModInt operator+(const ModInt l,const ModInt r){
  return add(l,r);
}

/**
* @param[in] l ModInt
* @param[in] r ModInt
*/
inline ModInt operator*(const ModInt l,const ModInt r){
  return mul(l,r);
}

/**
* @param[in] l ModInt
* @param[in] r ModInt
*/
inline ModInt operator-(const ModInt l,const ModInt r){
  return add(l,-r);
}

/**
* @param[in] l ModInt
* @param[in] r int
* @details 右辺は定数を想定しているのでmodをとらないrawを使ってModIntに変換している．ただしmodより大きい値や負の数を入れると事故るので注意．
*/
inline ModInt operator+(const ModInt l,const int r){
  return add(l,ModInt::raw(r));
}

/**
* @param[in] l ModInt
* @param[in] r int
*/
inline ModInt operator+(const ModInt l,const long long r){
  return add(l,ModInt::get(r));
}

/**
* @param[in] l ModInt
* @param[in] r int
* @details 右辺は定数を想定しているのでmodをとらないrawを使ってModIntに変換している．ただしmodより大きい値や負の数を入れると事故るので注意．
*/
inline ModInt operator*(const ModInt l,const int r){
  return mul(l,ModInt::raw(r));
}

/**
* @param[in] l ModInt
* @param[in] r int
*/
inline ModInt operator*(const ModInt l,const long long r){
  return mul(l,ModInt::get(r));
}

/**
* @param[in] l ModInt
* @param[in] r int
* @details 右辺は定数を想定しているのでmodをとらないrawを使ってModIntに変換している．ただしmodより大きい値や負の数を入れると事故るので注意．
*/
inline ModInt operator-(const ModInt l,const int r){
  return add(l,ModInt::raw(mod-r));
}

/**
* @param[in] l ModInt
* @param[in] r int
*/
inline ModInt operator-(const ModInt l,const long long r){
  return add(l,-ModInt::get(r));
}

/**
* @param[in] l ModInt
* @param[in] r int
* @details 右辺は定数を想定しているのでmodをとらないrawを使ってModIntに変換している．ただしmodより大きい値や負の数を入れると事故るので注意．
*/
inline ModInt operator/(const ModInt l,const int r){
  return mul(l,inv(ModInt::raw(r)));
}

/**
* @param[in] l ModInt
* @param[in] r int
*/
inline ModInt operator/(const ModInt l,const long long r){
  return mul(l,inv(ModInt::get(r)));
}

/**
* @param[in] l ModInt
* @param[in] r long long
* @details
*   pow(l,r)を呼び出すだけなのでpowを参照のこと．
  計算量はO(log mod)
*/
inline ModInt operator^(const ModInt l,const long long r){
  return pow(l,r);
}

/**
* @namespace factorial
* @brief 順列数関連の関数のまとめ
* @details
*   - combination
*   - permutation
*/
namespace factorial{
  //! 順列数を格納する配列のサイズ
  constexpr int size = 1123456;

  //! 前計算ができているかどうかのフラグ
  bool is_build = false;

  //! 順列数を格納する配列
  ModInt factorial[size];
  //! (順列数)^-1を格納する配列
  ModInt inverse_factorial[size];

  /**
  * @brief 順列数の前計算
  * @details
  *   順列数と，その逆元を[0,size)まで求める.
  *   計算量は，O(size + log(mod))
  */
  void build(){
    is_build = true;
    factorial[0]=1;
    for(int i=1;i<size;i++){
      factorial[i]=factorial[i-1]*i;
    }
    inverse_factorial[size-1]=inv(factorial[size-1]);
    for(int i=size-1;i>=1;i--){
      inverse_factorial[i-1]=inverse_factorial[i]*i;
    }
  }

  /**
  * @brief nPkを求める
  * @details
  *   前計算がしてあれば O(1)．前計算してない場合は is_build を読み取って前計算をする．
  */
  inline ModInt permutation(int n,int k){
    if(k<0 || k>n) return ModInt::raw(0);
    if(!is_build)build();
    return factorial[n]*inverse_factorial[n-k];
  }

  /**
  * @brief nCkを求める
  * @details
  *   前計算がしてあれば O(1)．前計算してない場合は is_build を読み取って前計算をする．
  */
  inline ModInt combination(int n, int k){
    if(k<0 || k>n) return ModInt::raw(0);
    if(!is_build)build();
    return factorial[n]*inverse_factorial[k]*inverse_factorial[n-k];
  }
}

//LLの数値をつかう時は最後にLLをつける癖をつけよう

BEGIN_SOLVER

///////////////////////////////////////////////////////////////////////////////////
// VARIABLE
///////////////////////////////////////////////////////////////////////////////////

ll a, b, x;

///////////////////////////////////////////////////////////////////////////////////
// SOLVER
///////////////////////////////////////////////////////////////////////////////////

solver(){
  input();
  solve();
  output();
}

///////////////////////////////////////////////////////////////////////////////////
// INPUT
///////////////////////////////////////////////////////////////////////////////////

void input(){
  cin >> a >> b >> x;
}

///////////////////////////////////////////////////////////////////////////////////
// SOLVE
///////////////////////////////////////////////////////////////////////////////////

void solve(){
  if (x < a) {
    cout << x % mod << endl;
    return;
  }
  ModInt l((x - a) / (a - b));
  ModInt a1(a);
  ModInt b1(b);
  ModInt x1(x);
  cout << *((l + 1) * a1 + x1 - (a1 - b1) * (l + 1)) << endl;
}

///////////////////////////////////////////////////////////////////////////////////
// OUTPUT
///////////////////////////////////////////////////////////////////////////////////

void output(){

}

///////////////////////////////////////////////////////////////////////////////////
// NOTE
///////////////////////////////////////////////////////////////////////////////////



///////////////////////////////////////////////////////////////////////////////////
// TEMPLATE(data structure)
///////////////////////////////////////////////////////////////////////////////////

class UnionFind {
public:
  explicit UnionFind(int _n) : n(_n) {
    par.resize(_n);
    rank.resize(_n);
    sizes.resize(_n);
    for (int i = 0; i < _n; i++) {
      par[i] = i;
      rank[i] = 0;
      sizes[i] = 1;
    }
  }
  int find(int a) {
    if (par[a] == a) return a;
    return par[a] = find(par[a]);
  }
  bool same(int a, int b) {
    return find(a) == find(b);
  }
  void unite(int a, int b) {
    link(find(a), find(b));
  }
  int size(int a) {
    return sizes[find(a)];
  }
  void view() {
    for (int i = 0; i < n; i++) {
      cout << " par" << "[" << i << "]=" << par[i] << ((i == n - 1) ? "\n" : ",");
    }
    for (int i = 0; i < n; i++) {
      cout << "size" << "[" << i << "]=" << sizes[i] << ((i == n - 1) ? "\n" : ",");
    }
    cout << endl;
  }
private:
  void link(int a, int b) {
    if (same(a, b)) return;
    if (rank[a] > rank[b]) {
      par[b] = a;
      sizes[a] += sizes[b];
      sizes[b] = 0;
    } else {
      par[a] = b;
      if (rank[a] == rank[b]) rank[b]++;
      sizes[b] += sizes[a];
      sizes[a] = 0;
    }
  }
  int n;
  vector<int> par;
  vector<int> rank;
  vector<int> sizes;
};

template <typename T>
class IntervalTree {
  using F = function<T(T, T)>;
public:
  IntervalTree(int n, const F func, const T init) : func(func), init(init) {
    size = 1;
    while ((int)size < n) size <<= 1;
    table.assign(2 * size, init);
  }
  void set(int k, T &x) {
    table[size + k] = x;
  }
  void build() {
    for (int i = size - 1; i >= 0; --i) {
      table[i] = func(table[i * 2], table[i * 2 + 1]);
    }
  }
  void update(int k, const T &x) {
    k += size;
    table[k] = x;
    while (k >>= 1) {
      table[k] = func(table[k * 2], table[k * 2 + 1]);
    }
  }
  T query(int a, int b) {
    T L = init, R = init;
    for (a += size, b += size; a < b; a >>= 1, b >>= 1) {
      if (a & 1) L = func(L, table[a++]);
      if (b & 1) R = func(table[--b], R);
    }
    return func(L, R);
  }
  T operator[](const int k) const {
    return table[k + size];
  }
private:
  unsigned int size;
  vector<T> table;
  const F func;
  const T init;
};


template <typename T>
class BIT {
public:
  BIT(int size) {
    BITTable.assign(++size, 0);
  }
  T sum(int k) {
    T res = 0;
    for (++k; k > 0; k -= k & -k) {
      res += BITTable[k];
    }
    return res;
  }
  T sum(int l, int r) {
    if (l == 0) return sum(r);
    return sum(r) - sum(l - 1);
  }
  void update(int k, T x) { // b[k] += x;
    for (++k; k < (int)BITTable.size(); k += k & -k) BITTable[k] += x;
  }
private:
  vector<T> BITTable;
};

END_SOLVER

///////////////////////////////////////////////////////////////////////////////////
// MAIN
///////////////////////////////////////////////////////////////////////////////////

int main() {
  solver ans;
#ifdef LOCAL_DEFINE
  cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s." << endl;
  //show(MOD);
#endif
  return 0;
}

