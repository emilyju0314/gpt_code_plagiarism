#include <bits/stdc++.h>
#include <stdexcept>
using namespace std;

#define REP(i,a,b) for(int i=a;i<(int)b;i++)
#define rep(i,n) REP(i,0,n)
#define all(c) (c).begin(), (c).end()
#define zero(a) memset(a, 0, sizeof a)
#define minus(a) memset(a, -1, sizeof a)
#define watch(a) { cout << #a << " = " << a << endl; }
template<class T1, class T2> inline bool minimize(T1 &a, T2 b) { return b < a && (a = b, 1); }
template<class T1, class T2> inline bool maximize(T1 &a, T2 b) { return a < b && (a = b, 1); }

typedef long long ll;
int const inf = 1<<29;

string S;
int idx;
int N, M;
string alphas;
int curr;

void consume(char c) {
  if(idx >= N) throw exception();
  if(S[idx] != c) throw exception();
  idx ++;
}

bool try_consume(char c) {
  try {
    consume(c);
  } catch(exception e) {
    return false;
  }
  return true;
}

int E();

int convert(string const& b) {
  int n = b.size();
  int ret = 0;
  for(int i=0; i<n; i++) {
    ret *= 2;
    assert(isdigit(b[i]));
    ret += b[i] - '0';
  }
  return ret;
}

string B() {
  string ret;
  while(1) {
    if(S[idx] == '0') ret += '0';
    else if(S[idx] == '1') ret += '1';
    else break;
    idx++;
  }
  return ret;
}

int Nu() {
  if(try_consume('0')) return 0;
  consume('1');
  return convert("1" + B());
}

int F() {
  if(try_consume('-')) {
    return -F();
  }
  else if(try_consume('(')) {
    int r = E();
    consume(')');
    return r;
  }
  else {
    return Nu();
  }
}

int T() {
  int num1 = F();
  while(try_consume('*')) {
    int num2 = F();
    num1 *= num2;
  }
  return num1;
}

int E() {
  int term1 = T();
  while(1) {
    bool cont = 0;
    while(try_consume('+')) {
      cont = 1;
      int term2 = T();
      term1 += term2;
    }
    while(try_consume('-')) {
      cont = 1;
      int term2 = T();
      term1 -= term2;
    }
    if(!cont) break;
  }
  return term1;
}

bool Q() {
  int expr1 = E();
  consume('=');
  int expr2 = E();
  return expr1 == expr2 && idx == N;
}

int main() {

  string T = "01+-*()=";
  sort(T.begin(), T.end());
  string RS; cin >> RS;
  N = RS.size();
  for(auto c: RS) if(isalpha(c)) alphas.push_back(c);
  sort(alphas.begin(), alphas.end());
  alphas.erase(unique(alphas.begin(), alphas.end()), alphas.end());
  M = alphas.size();

  if(M > T.size()) {
    cout << 0 << endl;
    return 0;
  }

  int ans = 0;
  set<string> st;
  do {
    S = RS;
    rep(i, N) {
      if(isalpha(S[i])) S[i] = T[alphas.find(S[i])];
    }
    if(!st.count(S)) {
      st.insert(S);
      idx = curr = 0;
      try { ans += Q(); } catch (exception e) {}
    }
  } while(next_permutation(T.begin(), T.end()));
  
  cout << ans << endl;

  return 0;
}