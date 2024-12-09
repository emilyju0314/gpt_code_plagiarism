#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
template <class T>
inline bool MX(T &l, const T &r) {
  return l < r ? l = r, 1 : 0;
}
template <class T>
inline bool MN(T &l, const T &r) {
  return l > r ? l = r, 1 : 0;
}
int N;
vector<long long> as, bs;
vector<char> ans;
long long sec;
void Imp() {
  cout << "IMPOSSIBLE\n";
  exit(0);
}
void Answer() {
  if (sec > 200000) {
    cout << "BIG\n";
    cout << sec << endl;
    exit(0);
  }
  cout << "SMALL\n";
  cout << ans.size() << endl;
  reverse((ans).begin(), (ans).end());
  for (char c : ans) cout << c;
  cout << endl;
  exit(0);
}
void Extra() {
  multiset<long long> ast, bst;
  for (int(i) = 0; (i) < (2); ++(i)) {
    ast.insert(as[i]);
    bst.insert(bs[i]);
  }
  bool found = 0;
  long long ad = -1;
  for (int(i) = 0; (i) < (2); ++(i)) {
    for (int(j) = 0; (j) < (1); ++(j)) {
      if (as[i] == bs[j]) {
        ad = as[i];
        ast.erase(ast.find(as[i]));
        bst.erase(bst.find(bs[j]));
        found = 1;
        break;
      }
    }
    if (found) break;
  }
  assert(found && ast.size() == 1 && bst.size() == 1);
  long long p = *ast.begin();
  long long q = *bst.begin();
  if ((q - p) % ad) Imp();
  long long t = (q - p) / ad;
  if (t + sec <= 200000) {
    for (int(i) = 0; (i) < (t); ++(i)) {
      ans.emplace_back('P');
    }
    if (as[0] > as[1]) ans.emplace_back('R');
    reverse((ans).begin(), (ans).end());
    cout << "SMALL\n";
    cout << ans.size() << endl;
    for (char c : ans) cout << c;
    cout << endl;
    exit(0);
  }
  cout << "BIG\n";
  cout << t + sec << endl;
  exit(0);
}
void Check() {
  int cnt = 0;
  for (int(j) = 0; (j) < (2); ++(j)) {
    bool doubt = 0;
    for (int(i) = 0; (i) < (N); ++(i)) {
      if (as[i] > bs[i]) {
        doubt = 1;
        break;
      }
    }
    cnt += doubt;
    reverse((as).begin(), (as).end());
  }
  if (cnt == 2) {
    Imp();
  }
}
void Gcd() {
  ans.clear();
  vector<long long> ts;
  if (bs[0] > bs[1]) {
    ans.emplace_back('R');
    swap(bs[0], bs[1]);
  }
  long long cnt = 0;
  while (1) {
    if (bs[0] == as[1] || bs[0] == as[0]) {
      break;
    }
    Check();
    long long h = bs[1] / bs[0];
    ts.emplace_back(h);
    cnt += h;
    bs[1] = bs[1] % bs[0];
    swap(bs[0], bs[1]);
  }
  multiset<long long> ast, bst;
  for (int(i) = 0; (i) < (2); ++(i)) {
    ast.insert(as[i]);
    bst.insert(bs[i]);
  }
  bool found = 0;
  long long ad = -1;
  for (int(i) = 0; (i) < (2); ++(i)) {
    for (int(j) = 0; (j) < (1); ++(j)) {
      if (as[i] == bs[j]) {
        ad = as[i];
        ast.erase(ast.find(as[i]));
        bst.erase(bst.find(bs[j]));
        found = 1;
        break;
      }
    }
    if (found) break;
  }
  assert(found && ast.size() == 1 && bst.size() == 1);
  long long p = *ast.begin();
  long long q = *bst.begin();
  if ((q - p) % ad) Imp();
  long long t = (q - p) / ad;
  if (cnt + t + sec <= 200000) {
    for (long long g : ts) {
      for (int(i) = 0; (i) < (g); ++(i)) {
        ans.emplace_back('P');
      }
      ans.emplace_back('R');
    }
    for (int(i) = 0; (i) < (t); ++(i)) {
      ans.emplace_back('P');
    }
    if (as[0] > as[1]) ans.emplace_back('R');
    reverse((ans).begin(), (ans).end());
    cout << "SMALL\n";
    cout << ans.size() << endl;
    for (char c : ans) cout << c;
    cout << endl;
    exit(0);
  }
  cout << "BIG\n";
  cout << cnt + t + sec << endl;
  exit(0);
}
signed main() {
  ios_base::sync_with_stdio(false);
  cout << fixed << setprecision(0);
  cin >> N;
  for (int(i) = 0; (i) < (N); ++(i)) {
    long long a;
    cin >> a;
    as.emplace_back(a);
  }
  for (int(i) = 0; (i) < (N); ++(i)) {
    long long a;
    cin >> a;
    bs.emplace_back(a);
  }
  if (N == 1) {
    if (as[0] == bs[0]) Answer();
    Imp();
  }
  if (N == 2) {
    Gcd();
  }
  Check();
  bool considered = 0;
  auto ras = as;
  reverse((ras).begin(), (ras).end());
  while (1) {
    if (as == bs) {
      Answer();
    }
    if (ras == bs) {
      ans.emplace_back('R');
      Answer();
    }
    if (N == 2 && !considered) {
      bool cond = as[1] == bs[0] || as[0] == bs[0];
      if (cond) {
        Extra();
        considered = 1;
      }
    }
    if (bs[0] > bs[N - 1]) {
      ans.emplace_back('R');
      reverse((bs).begin(), (bs).end());
    }
    ans.emplace_back('P');
    sec++;
    for (int(i) = (N)-1; (i) >= (1); --(i)) {
      bs[i] -= bs[i - 1];
      if (bs[i] < 1) {
        Imp();
      }
    }
    if (bs[0] < 1) Imp();
  }
}
