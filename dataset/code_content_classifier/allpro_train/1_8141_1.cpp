// includes
#include <bits/stdc++.h>
using namespace std;

// macros
#define pb emplace_back
#define mk make_pair
#define FOR(i, a, b) for(int i=(a);i<(b);++i)
#define rep(i, n) FOR(i, 0, n)
#define rrep(i, n) for(int i=((int)(n)-1);i>=0;i--)
#define irep(itr, st) for(auto itr = (st).begin(); itr != (st).end(); ++itr)
#define irrep(itr, st) for(auto itr = (st).rbegin(); itr != (st).rend(); ++itr)
#define all(x) (x).begin(),(x).end()
#define sz(x) ((int)(x).size())
#define UNIQUE(v) v.erase(unique(v.begin(), v.end()), v.end())
#define bit(n) (1LL<<(n))
// functions
template <class T>bool chmax(T &a, const T &b){if(a < b){a = b; return 1;} return 0;}
template <class T>bool chmin(T &a, const T &b){if(a > b){a = b; return 1;} return 0;}
template <typename T> istream &operator>>(istream &is, vector<T> &vec){for(auto &v: vec)is >> v; return is;}
template <typename T> ostream &operator<<(ostream &os, const vector<T>& vec){for(int i = 0; i < vec.size(); i++){ os << vec[i]; if(i + 1 != vec.size())os << " ";} return os;}
template <typename T> ostream &operator<<(ostream &os, const set<T>& st){for(auto itr = st.begin(); itr != st.end(); ++itr){ os << *itr; auto titr = itr; if(++titr != st.end())os << " ";} return os;}
template <typename T> ostream &operator<<(ostream &os, const unordered_set<T>& st){for(auto itr = st.begin(); itr != st.end(); ++itr){ os << *itr; auto titr = itr; if(++titr != st.end())os << " ";} return os;}
template <typename T> ostream &operator<<(ostream &os, const multiset<T>& st){for(auto itr = st.begin(); itr != st.end(); ++itr){ os << *itr; auto titr = itr; if(++titr != st.end())os << " ";} return os;}
template <typename T> ostream &operator<<(ostream &os, const unordered_multiset<T>& st){for(auto itr = st.begin(); itr != st.end(); ++itr){ os << *itr; auto titr = itr; if(++titr != st.end())os << " ";} return os;}
template <typename T1, typename T2> ostream &operator<<(ostream &os, const pair<T1, T2> &p){os << p.first << " " << p.second; return os;}
template <typename T1, typename T2> ostream &operator<<(ostream &os, const map<T1, T2> &mp){for(auto itr = mp.begin(); itr != mp.end(); ++itr){ os << itr->first << ":" << itr->second; auto titr = itr; if(++titr != mp.end())os << " "; } return os;}
template <typename T1, typename T2> ostream &operator<<(ostream &os, const unordered_map<T1, T2> &mp){for(auto itr = mp.begin(); itr != mp.end(); ++itr){ os << itr->first << ":" << itr->second; auto titr = itr; if(++titr != mp.end())os << " "; } return os;}
//  types
using ll = long long int;
using P = pair<int, int>;
// constants
const int inf = 1e9;
const ll linf = 1LL << 50;
const double EPS = 1e-10;
const int mod = 1000000007;
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, -1, 0, 1};
// io
struct fast_io{
  fast_io(){ios_base::sync_with_stdio(false); cin.tie(0); cout << fixed << setprecision(20);}
} fast_io_;

using cd = complex<double>;

template<typename T>
T extgcd(T a, T b, T &x, T &y){ 
  T d = a;
  if(b != 0){
    d = extgcd(b, a % b, y, x);
    y -= (a / b) * x;
  }else{
    x = 1, y = 0;
  }
  return d;
}

template <typename T>
T modinv(T a, T m){
  long long x = 0, y = 0;
  extgcd<long long>(a, m, x, y);
  x %= m;
  if(x < 0)x += m;
  return x;
}

template <typename T>
long long garner(vector<T> b, vector<T> m, T MOD){
  m.emplace_back(MOD);
  vector<long long> coef(m.size(), 1);
  vector<long long> consts(m.size(), 0);
  for(int i = 0; i < b.size(); i++){
    long long t = ((b[i] - consts[i]) % m[i]) * modinv<long long>(coef[i], m[i]) % m[i];
    for(int j = i + 1; j < m.size(); j++){
      consts[j] = (consts[j] + t * coef[j] % m[j]) % m[j];
      coef[j] = coef[j] * m[i] % m[j];
    }
  }
  return consts.back();
}

template <typename T>
T power(T a, T n, T mod) {
  T res = 1;
  T tmp = n;
  T curr = a;
  while(tmp){
    if(tmp % 2 == 1){
      res = (T)(res * curr % mod);
    }
    curr = (T)(curr * curr % mod);
    tmp >>= 1;
  }

  return res;
}


// f.size() should be the power of 2.
void rec_fft(vector<cd> &f, bool inv=false){
  int n = f.size();
  if(n == 1)return;
  vector<cd> f0(n / 2), f1(n / 2);
  for(int i = 0; i < n / 2; i++){
    f0[i] = f[i * 2];
    f1[i] = f[i * 2 + 1];
  }
  rec_fft(f0, inv);
  rec_fft(f1, inv);
  double th = M_PI * 2 / n;
  if(inv)th = - th;
  cd u(cos(th), sin(th)), ui(1, 0);
  for(int i = 0; i < n; i++){
    f[i] = f0[i%(n/2)] + ui * f1[i%(n/2)];
    ui = ui * u;
  }
}

// f.size() should be the power of 2.
void fft(vector<cd> &f, bool inv=false){
  int n = f.size(), mask = n - 1;
  vector<cd> tmp(n);
  for(int i = n >> 1; i >= 1; i >>= 1){
    cd zeta = polar(1., 2. * M_PI * i * (inv ? -1.: 1.) / n);
    cd w = 1;
    for(int j = 0; j < n; j += i){
      for(int k = 0; k < i; k++){
        tmp[j + k] = f[((j<<1)&mask) + k] + w * f[(((j<<1)+i)&mask)+k];
      }
      w *= zeta;
    }
    swap(f, tmp);
  }
}

void dft(vector<cd> &f){
  fft(f);
}

void idft(vector<cd> &f){
  fft(f, true);
  for(size_t i = 0; i < f.size(); i++)f[i] = f[i] / cd(f.size());
}

template <typename T>
vector<T> convolution(const vector<T> &f, const vector<T> &g){
  int n = 1;
  while(n < 2 * f.size() + 1)n *= 2;
  vector<cd> F(n, 0), G(n, 0);
  for(int i = 0; i < f.size(); i++)F[i] = cd(f[i]);
  for(int i = 0; i < g.size(); i++)G[i] = cd(g[i]);

  dft(F);
  dft(G);
  vector<cd> H(n);
  for(int i = 0; i < n; i++)H[i] = F[i] * G[i];
  idft(H);
  vector<T> h(n);
  for(int i = 0; i < n; i++){
    h[i] = T(round(H[i].real()));
  }
  return h;
}

template <int MOD, int g>
struct NTT{
  int get_mod(){
    return MOD;
  }
  void _ntt(vector<long long> &f, bool inv=false){
    int n = f.size(), mask = n - 1;
    int h = power<long long>(g, (MOD - 1) / n, MOD);
    if(inv)h = modinv(h, MOD);
    vector<long long> tmp(n);
    for(int i = n >> 1; i >= 1; i >>= 1){
      long long zeta = power<long long>(h, i, MOD);
      long long w = 1;
      for(int j = 0; j < n; j += i){
        for(int k = 0; k < i; k++){
          tmp[j+k] = (f[((j<<1)&mask)+k] + w * f[(((j<<1)+i)&mask)+k] % MOD) % MOD;
        }
        w = w * zeta % MOD;
      }
      swap(f, tmp);
    }
  }
  void ntt(vector<long long> &f){
    _ntt(f, false);
  }
  void intt(vector<long long> &f){
    _ntt(f, true);
    int n = f.size();
    int ni = modinv(n, MOD);
    for(int i = 0; i < n; i++)f[i] = f[i] * ni % MOD;
  }
  vector<long long> convolution(vector<long long> f, vector<long long> h){
    int n = 1;
    while(n < int(f.size() + h.size()))n *= 2;
    f.resize(n, 0); h.resize(n, 0);
    ntt(f);
    ntt(h);
    for(int i = 0; i < n; i++)f[i] = f[i] * h[i] % MOD;
    intt(f);
    return f;
  }
};

using NTT1 = NTT<167772161, 3>;
using NTT2 = NTT<469762049, 3>;
using NTT3 = NTT<1224736769, 3>;

vector<long long> arbitrary_mod_convolution(vector<long long> f, vector<long long> g, long long MOD){
  for(size_t i = 0; i < f.size(); i++)f[i] %= MOD;
  for(size_t i = 0; i < g.size(); i++)g[i] %= MOD;
  NTT1 ntt1;
  NTT2 ntt2;
  NTT3 ntt3;
  auto x1 = ntt1.convolution(f, g);
  auto x2 = ntt2.convolution(f, g);
  auto x3 = ntt3.convolution(f, g);

  vector<long long> res(x1.size());
  vector<long long> b(3), m(3);
  m[0] = ntt1.get_mod();
  m[1] = ntt2.get_mod();
  m[2] = ntt3.get_mod();
  for(size_t i = 0; i < x1.size(); i++){
    b[0] = x1[i];
    b[1] = x2[i];
    b[2] = x3[i];
    res[i] = garner<long long>(b, m, MOD);
  }
  return res;
}
//// begin library bigint here
//// usage of this library: Bigint b = x;
vector<ll> convert_base(const vector<ll> &v, int old_b, int new_b){
  vector<ll> p(max(new_b, old_b) + 1);
  p[0] = 1;
  for(int i = 1; i < p.size(); i++)p[i] = p[i-1] * 10;
  vector<ll> res;
  ll curr = 0;
  int curr_b = 0;
  for(int i = 0; i < v.size(); i++){
    curr += v[i] * p[curr_b];
    curr_b += old_b;
    while(curr_b >= new_b){
      res.push_back(curr % p[new_b]);
      curr /= p[new_b];
      curr_b -= new_b;
    }
  }
  res.push_back(curr);
  while(!res.empty() && res.back() == 0)res.pop_back();
  return res;
}

vector<ll> simple_multiply(const vector<ll> &x, const vector<ll> &y){
  vector<ll> res(x.size() + y.size() - 1, 0);
  for(int i = 0; i < x.size(); i++){
    for(int j = 0; j < y.size(); j++){
      res[i+j] += x[i] * y[j];
    }
  }
  while(!res.empty() && res.back() == 0)res.pop_back();
  return res;
}

vector<ll> fft_multiply(const vector<ll> &x, const vector<ll> &y){
  int n = max(x.size(), y.size());
  vector<ll> a = x, b = y;
  a.resize(n, 0);
  b.resize(n, 0);
  vector<ll> conv = convolution<ll>(a, b);
  while(!conv.empty() && conv.back() == 0)conv.pop_back();
  return conv;
}

vector<ll> karatsuba_multiply(const vector<ll> &x, const vector<ll> &y){
  int n = max(x.size(), y.size());
  int m = 0;
  while((1 << m) < n)m++;
  n = (1 << m);
  vector<ll> a = x, b = y;
  a.resize(n, 0);
  b.resize(n, 0);
  if(n <= 32){
    return simple_multiply(a, b);
  }

  int k = n >> 1;
  vector<ll> a1(a.begin(), a.begin() + k);
  vector<ll> a2(a.begin() + k, a.end());
  vector<ll> b1(b.begin(), b.begin() + k);
  vector<ll> b2(b.begin() + k, b.end());

  vector<ll> a1b1 = karatsuba_multiply(a1, b1);
  vector<ll> a2b2 = karatsuba_multiply(a2, b2);
  for(int i = 0; i < k; i++)a2[i] += a1[i];
  for(int i = 0; i < k; i++)b2[i] += b1[i];
  vector<ll> z = karatsuba_multiply(a2, b2);
  for(int i = 0; i < a1b1.size(); i++)z[i] -= a1b1[i];
  for(int i = 0; i < a2b2.size(); i++)z[i] -= a2b2[i];

  vector<ll> res(2 * n, 0);
  for(int i = 0; i < a1b1.size(); i++)res[i] += a1b1[i];
  for(int i = 0; i < a2b2.size(); i++)res[i + n] += a2b2[i];
  for(int i = 0; i < z.size(); i++)res[i + k] += z[i];
  while(!res.empty() && res.back() == 0)res.pop_back();
  return res;
}

struct Bigint{
  const ll base = 100000000;
  const ll mbase = 1000; // 1000 for FFT, 10000 otherwise
  const int b = 8;
  const int mb = 3; // 3 for FFT, 10000 otherwise
  int sign = 1;
  vector<ll> dg;
  Bigint(){}
  Bigint(ll x){
    if(x < 0){
      sign = -1;
      x *= -1;
    }
    while(x){
      dg.push_back(x % base);
      x /= base;
    }
  }
  Bigint(const string &s){
    int e = 0;
    if(s[0] == '-'){
      sign = -1;
      e++;
    }
    for(int i = int(s.size()) - 1; i >= e; i-=b){
      int B = (i - b + 1 >= e ? b: i + 1 - e);
      ll x = stoll(s.substr(max(e, i - b + 1), B));
      dg.push_back(x);
    }
  }
  Bigint& operator=(const string &s){
    *this = Bigint(s);
    return *this;
  }
  Bigint& operator=(const Bigint &x){
    sign = x.sign;
    dg = x.dg;
    return *this;
  }
  Bigint& operator=(ll x){
    return (*this = Bigint(x));
  }
  Bigint operator-() const{
    Bigint res = *this;
    res.sign *= -1;
    return res;
  }
  Bigint operator+(const Bigint &x) const{
    if(sign == x.sign){
      Bigint res;
      res.sign = sign;
      res.dg.resize(max(dg.size(), x.dg.size()));
      ll carry = 0;
      for(int i = 0; i < max(dg.size(), x.dg.size()); i++){
        ll tmp = carry;
        if(i < dg.size())tmp += dg[i];
        if(i < x.dg.size())tmp += x.dg[i];
        res.dg[i] = (tmp % base);
        carry = tmp / base;
      }
      while(carry){
        res.dg.push_back(carry % base);
        carry /= base;
      }
      return res;
    }else{
      return (*this - (- x));
    }
  }
  void trim(){
    while(!dg.empty() && dg.back() == 0)dg.pop_back();
    if(dg.empty())sign = 1;
  }
  Bigint abs() const{
    Bigint res = *this;
    res.sign = 1;
    return res;
  }
  Bigint operator-(const Bigint &x) const{
    if(sign == x.sign){
      if(abs() >= x.abs()){
        Bigint res = *this;
        ll carry = 0;
        for(int i = 0; i < x.dg.size(); i++){
          res.dg[i] -= carry + x.dg[i];
          if(res.dg[i] < 0){
            res.dg[i] += base;
            carry = 1;
          }else{
            carry = 0;
          }
        }
        if(carry > 0){
          for(int i = x.dg.size(); i < res.dg.size() && carry > 0; i++){
            res.dg[i] -= carry;
            if(res.dg[i] < 0){
              res.dg[i] += base;
              carry = 1;
            }else{
              carry = 0;
            }
          }
        }
        res.trim();
        return res;
      }else{
        return - (x - *this);
      }
    }else{
      return (*this + (- x));
    }
  }
  bool operator<(const Bigint &x) const{
    if(sign != x.sign)return sign < x.sign;
    if(dg.size() != x.dg.size())return int(dg.size()) * sign < int(x.dg.size()) * x.sign;
    for(int i = int(dg.size()) - 1; i >= 0; i--){
      if(dg[i] != x.dg[i])return dg[i] * sign < x.dg[i] * x.sign;
    }
    return false;
  }
  bool operator>(const Bigint &x) const{
    return x < *this;
  }
  bool operator<=(const Bigint &x) const{
    return !(*this > x);
  }
  bool operator>=(const Bigint &x) const{
    return !(*this < x);
  }
  bool operator==(const Bigint &x) const{
    return !(*this < x) && !(x < *this);
  }
  bool operator!=(const Bigint &x) const{
    return (*this < x) || (x < *this);
  }
  friend istream& operator>>(istream &is, Bigint &x){
    string s;
    is >> s;
    x = s;
    return is;
  }
  friend ostream& operator<<(ostream& os, const Bigint &x){
    if(x.sign < 0)os << '-';
    if(x.dg.empty())os << 0;
    else{
      os << x.dg.back();
      for(int i = int(x.dg.size()) - 2; i >= 0; i--){
        os << setw(x.b) << setfill('0') << x.dg[i];
      }
    }
    return os;
  }
  Bigint& operator*=(ll x){
    if(x < 0){
      x *= -1;
      sign *= -1;
    }
    ll carry = 0;
    for(int i = 0; i < dg.size(); i++){
      carry = dg[i] * x + carry;
      dg[i] = carry % base;
      carry /= base;
    }
    while(carry){
      dg.push_back(carry % base);
      carry /= base;
    }
    trim();
    return *this;
  }
  Bigint operator*(ll x) const{
    Bigint res = *this;
    res *= x;
    return res;
  }
  Bigint operator*(const Bigint &v) const{
    vector<ll> x = convert_base(dg, b, mb);
    vector<ll> y = convert_base(v.dg, b, mb);

    if(x.empty())x.push_back(0);
    if(y.empty())y.push_back(0);
    // simple multiplication
    // vector<ll> mul = simple_multiply(x, y);
    // FFT
    vector<ll> mul = fft_multiply(x, y);
    // karatsuba
    // vector<ll> mul = karatsuba_multiply(x, y);

    Bigint res;
    res.sign = sign * v.sign;
    ll carry = 0;
    for(int i = 0; i < mul.size(); i++){
      carry += mul[i];
      res.dg.push_back(carry % mbase);
      carry /= mbase;
    }
    while(carry){
      res.dg.push_back(carry % mbase);
      carry /= mbase;
    }
    res.dg = convert_base(res.dg, mb, b);
    res.trim();
    return res;
  }
  // a = bq + r
  pair<Bigint, Bigint> divmod(const Bigint &a1, const Bigint &b1) const{
    ll norm = base / (b1.dg.back() + 1);
    Bigint q, r;
    q.sign = a1.sign * b1.sign;
    r.sign = a1.sign;

    Bigint a = a1.abs() * norm;
    Bigint b = b1.abs() * norm;
    q.dg.resize(a.dg.size());

    for(int i = int(a.dg.size()) - 1; i >= 0; i--){
      r = r * base + a.dg[i];
      ll s1 = (r.dg.size() <= b.dg.size() ? 0: r.dg[b.dg.size()]);
      ll s2 = (r.dg.size() <= int(b.dg.size()) - 1 ? 0: r.dg[int(b.dg.size()) - 1]);
      // temporary solution
      ll d = (base * s1 + s2) / b.dg.back();
      r -= b * d;
      // feedback
      while(r < 0)r += b, d--;
      q.dg[i] = d;
    }

    q.trim();
    r.trim();
    return make_pair(q, r / norm);
  }
  Bigint operator/(const Bigint &x) const{
    return divmod(*this, x).first;
  }
  Bigint operator%(const Bigint &x) const{
    return divmod(*this, x).second;
  }
  Bigint& operator/=(ll x){
    if(x < 0){
      x *= -1;
      sign *= -1;
    }
    ll rem = 0;
    for(int i = int(dg.size()) - 1; i >= 0; i--){
      rem = dg[i] + rem * base;
      dg[i] = rem / x;
      rem = rem % x;
    }
    trim();
    return *this;
  }
  Bigint operator/(ll x) const{
    Bigint res = *this;
    res /= x;
    return res;
  }
  Bigint operator%(ll x) const{
    if(x < 0)x *= -1;
    ll m = 0;
    for(int i = int(dg.size()) - 1; i >= 0; i--){
      m = (dg[i] + m * base) % x;
    }
    return m * sign;
  }
  Bigint& operator+=(const Bigint &x){
    *this = *this + x;
    return *this;
  }
  Bigint& operator-=(const Bigint &x){
    *this = *this - x;
    return *this;
  }
  Bigint& operator*=(const Bigint &x){
    *this = *this * x;
    return *this;
  }
  Bigint& operator/=(const Bigint &x){
    *this = *this / x;
    return *this;
  }
  bool iszero(){
    trim();
    if(dg.empty())return false;
    return true;
  }
  ll long_value() const {
    ll res = 0;
    for(int i = int(dg.size()) - 1; i >= 0; i--){
      res = res * base + dg[i];
    }
    return res * sign;
  }
};
//// end library

int main(int argc, char const* argv[])
{
  Bigint a, b;
  cin >> a >> b;
  cout << a / b << endl;
  return 0;
}

