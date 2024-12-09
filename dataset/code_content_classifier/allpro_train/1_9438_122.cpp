#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <complex>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <iomanip>
#include <assert.h>
#include <array>
#include <cstdio>
#include <cstring>
#include <random>
#include <functional>
#include <numeric>
#include <bitset>
#include <fstream>

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

namespace solver {
string s;
typedef string::const_iterator Iter;
Iter it, end;
int priority[3];

#define my_assert(condition)  \
  if(!(condition)) {  \
    cout << string(it, end) << endl;  \
    assert(0 && #condition); \
  } \

void consume(char e) {
  my_assert(*it == e);
  it ++;
}

bool isconsume(char e) {
  if(*it == e) {
    consume(e);
    return true;
  }
  return false;
}

ll number() {
  ll ret = 0;
  my_assert(isdigit(*it));
  while(isdigit(*it)) {
    ret *= 10;
    ret += *it - '0';
    it ++;
  }
  return ret;
}

// 1. solve operator priority recursion
ll expr(int p) {
  if(p == 3) {
    if(isconsume('(')) {
      ll ret = expr(0);
      consume(')');
      return ret;
    }
    return number();
  }

  // 2. solve operator association
  ll ret = expr(p + 1);

  auto priority_condition = [&]() {
    auto k = string("+-*").find(*it);
    if(k == string::npos) return false;
    return priority[k] == p;
  };

  while(priority_condition())
    if(isconsume('+')) ret += expr(p + 1);
    else if(isconsume('-')) ret -= expr(p + 1);
    else if(isconsume('*')) ret *= expr(p + 1);

  return ret;
}

ll calc() {
  it = s.begin(), end = s.end();
  ll ret = expr(0);
  my_assert(it == end);
  return ret;
}

bool next_priority() {
  static int turn = 0;
  int t = turn++;
  priority[0] = t % 3;
  t /= 3;
  priority[1] = t % 3;
  t /= 3;
  if(t >= 3) return false;
  priority[2] = t;
  return true;
}

ll solve() {
  ll ret = numeric_limits<ll>::min();
  do {
    ret = max(ret, calc());
  } while(next_priority());
  return ret;
}

}

int main() {
  cin >> solver::s;
  cout << solver::solve() << endl;
  return 0;
}