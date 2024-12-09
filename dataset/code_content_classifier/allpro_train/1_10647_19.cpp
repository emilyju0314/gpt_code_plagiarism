#include <bits/stdc++.h>

using namespace std;

#define SZ(x) (int)(x.size())
#define REP(i, n) for(int i=0;i<(n);++i)
#define FOR(i, a, b) for(int i=(a);i<(b);++i)
#define RREP(i, n) for(int i=(int)(n);i>=0;--i)
#define RFOR(i, a, b) for(int i=(int)(a);i>=(int)(b);--i)
#define ALL(a) (a).begin(),(a).end()
#define DUMP(x) cerr<<#x<<" = "<<(x)<<endl
#define DEBUG(x) cerr<<#x<<" = "<<(x)<<" (L"<<__LINE__<<")"<< endl;

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
using vvll = vector<vll>;
using P = pair<int, int>;

const double eps = 1e-8;
const ll MOD = 1000000007;
const int INF = INT_MAX / 2;
const ll LINF = LLONG_MAX / 2;

template <typename T1, typename T2>
bool chmax(T1 &a, const T2 &b) {
  if(a < b) {a = b; return true;}
  return false;
}

template <typename T1, typename T2>
bool chmin(T1 &a, const T2 &b) {
  if(a > b) {a = b; return true;}
  return false;
}

template<typename T1, typename T2>
ostream& operator<<(ostream &os, const pair<T1, T2> p) {
  os << p.first << ":" << p.second;
  return os;
}

template<class T>
ostream &operator<<(ostream &os, const vector<T> &v) {
  REP(i, SZ(v)) {
    if(i) os << " ";
    os << v[i];
  }
  return os;
}

bool solve() {
  string in;
  getline(cin, in);
  if (in == "#") return false;
  string s;
  REP(i, SZ(in)) {
    if (in[i] != ' ') {
      s += in[i];
    }
  }
  s += ">>0";

  vll val = {-1};
  vll num = {0};

  REP(i, SZ(s)) {
    /*
    cout << i << endl;
    cout << val << endl;
    cout << num << endl;
    cout << endl;
     */
    if('0' <= s[i] && s[i] <= '9') {
      num.back() *= 10;
      num.back() += s[i] - '0';
    } else if(s[i] == 'S') {
      val.push_back(-1);
      num.push_back(0);
      i++;
    } else if(s[i] == '>' && i < SZ(s)-2 && s[i+1] == '>' && (('0' <= s[i+2] && s[i+2] <= '9') || s[i+2] == 'S')) {
      if(val.back() == -1) {
        val.back() = num.back();
        num.back() = 0;
      } else {
        while(val.back() > 0 && num.back() > 0) {
          val.back() /= 2;
          num.back()--;
        }
        num.back() = 0;
      }
      i++;
    } else if(s[i] == '>') {
      if(val.back() == -1) {
        val.back() = num.back();
        num.back() = 0;
      } else {
        while(val.back() > 0 && num.back() > 0) {
          val.back() /= 2;
          num.back()--;
        }
        num.back() = 0;
      }
      ll tmp = val.back();
      tmp *= tmp;
      tmp %= MOD;
      val.pop_back();
      num.pop_back();
      if(val.back() == -1) {
        val.back() = tmp;
      } else {
        while(val.back() > 0 && tmp > 0) {
          val.back() /= 2;
          tmp--;
        }
      }
    }
  }

  cout << val[0] << endl;
  return true;
}

int main() {

  while(solve()) {}

}







