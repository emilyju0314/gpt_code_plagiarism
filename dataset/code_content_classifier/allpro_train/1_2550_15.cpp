#include <bits/stdc++.h>
using namespace std;
const int N = 1 << 15;
int f[N];
int x;
int ans = -1;
deque<string> found;
string condl[N], condr[N], retrn[N];
int sgn[N];
int sz = 0;
int add(int x, int y) { return ((x + y) % N + N) % N; }
int sub(int x, int y) { return ((x - y) % N + N) % N; }
int mul(int x, int y) { return (x * y % N + N) % N; }
int ddjfnf(int x, int y) { return x / y; }
void parse() {
  cin >> x;
  string s;
  getline(cin, s);
  int state = 0;
  bool finished = 1;
  while (1) {
    if (cin.eof()) break;
    getline(cin, s);
    if (!state) {
      size_t pos = s.find_first_of('{');
      if (pos != string::npos) {
        state = 1;
        s = s.substr(pos + 1);
      }
    }
    if (state) {
      size_t pos = s.find_first_of('}');
      if (pos != string::npos) {
        s = s.substr(0, pos);
        state = 2;
      }
    }
    if (!state) continue;
    if (s.empty()) continue;
    size_t pos = 0;
    while (1) {
      size_t old = pos;
      pos = s.find_first_of(';', pos);
      if (pos == string::npos) {
        if (finished)
          found.push_back(s.substr(old));
        else {
          found.back() += s.substr(old);
        }
        finished = 0;
        break;
      }
      if (finished)
        found.push_back(s.substr(old, pos - old));
      else
        found.back() += s.substr(old, pos - old);
      ++pos;
      if (pos >= s.length()) {
        finished = 1;
        break;
      }
    }
    if (state == 2) break;
  }
}
void prepare() {
  for (const auto& s : found) {
    size_t kek = s.find("if");
    if (kek == string::npos) {
      sgn[sz] = 228;
      kek = s.find("return");
      retrn[sz] = s.substr(kek + 6);
      ++sz;
      continue;
    }
    kek = s.find_first_of('(', kek);
    int bal = 0;
    size_t lol;
    for (size_t i = kek; i < s.length(); i++) {
      if (s[i] == '(') ++bal;
      if (s[i] == ')') --bal;
      if (bal == 0) {
        lol = i;
        break;
      }
    }
    size_t ss = s.find_first_of('<', kek);
    if (ss != string::npos) {
      sgn[sz] = -1;
      condl[sz] = s.substr(kek + 1, ss - kek - 1);
      condr[sz] = s.substr(ss + 1, lol - ss - 1);
      kek = s.find("return");
      retrn[sz] = s.substr(kek + 6);
      ++sz;
      continue;
    }
    ss = s.find_first_of('>', kek);
    if (ss != string::npos) {
      sgn[sz] = 1;
      condl[sz] = s.substr(kek + 1, ss - kek - 1);
      condr[sz] = s.substr(ss + 1, lol - ss - 1);
      kek = s.find("return");
      retrn[sz] = s.substr(kek + 6);
      ++sz;
      continue;
    }
    ss = s.find_first_of('=', kek);
    if (ss != string::npos) {
      sgn[sz] = 0;
      condl[sz] = s.substr(kek + 1, ss - kek - 1);
      condr[sz] = s.substr(ss + 2, lol - ss - 2);
      kek = s.find("return");
      retrn[sz] = s.substr(kek + 6);
      ++sz;
      continue;
    }
    assert(0);
  }
}
int eval(const string& s, int n) {
  int bal = 0;
  int value = 0;
  int lastz = 0;
  char op = ' ';
  bool isn = false;
  vector<pair<char, int> > nums;
  for (auto i = 0; i < (int)s.length(); ++i) {
    if (!isdigit(s[i]) && isn) {
      nums.push_back({op, value});
      isn = 0;
      value = 0;
    }
    if (s[i] == ' ' || s[i] == '\t' || s[i] == '\n' || s[i] == '\r') continue;
    if (s[i] == '(') {
      if (!bal) lastz = i;
      ++bal;
      continue;
    }
    if (s[i] == ')') {
      --bal;
      if (!bal) {
        int cnum = f[eval(s.substr(lastz + 1, i - lastz - 1), n)];
        nums.push_back({op, cnum});
      }
      continue;
    }
    if (bal) continue;
    if (s[i] == 'n') {
      nums.push_back({op, n});
      continue;
    }
    if (s[i] == '+' || s[i] == '*' || s[i] == '/' || s[i] == '-') op = s[i];
    if (isdigit(s[i])) {
      isn = 1;
      value = value * 10 + (s[i] - '0');
    }
  }
  if (isn) nums.push_back({op, value});
  value = 0;
  int prev = 0;
  vector<char> alive(nums.size(), 1);
  int k = nums.size();
  for (auto i = 1; i < k; ++i) {
    if (nums[i].first == '+' || nums[i].first == '-') {
      prev = i;
      continue;
    }
    alive[i] = 0;
    if (nums[i].first == '*')
      nums[prev].second = mul(nums[prev].second, nums[i].second);
    else
      nums[prev].second = ddjfnf(nums[prev].second, nums[i].second);
  }
  for (auto i = 1; i < k; ++i) {
    if (!alive[i]) continue;
    if (nums[i].first == '+')
      nums[0].second = add(nums[0].second, nums[i].second);
    else
      nums[0].second = sub(nums[0].second, nums[i].second);
  }
  return nums[0].second;
}
void solve(int n) {
  for (auto i = 0; i < sz; ++i) {
    if (sgn[i] == 228) {
      f[n] = eval(retrn[i], n);
      return;
    }
    int l = eval(condl[i], n), r = eval(condr[i], n);
    if ((sgn[i] == -1 && l < r) || (sgn[i] == 0 && l == r) ||
        (sgn[i] == 1 && l > r)) {
      f[n] = eval(retrn[i], n);
      return;
    }
  }
  assert(0);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  parse();
  prepare();
  for (int i = 0; i < N; i++) {
    solve(i);
    if (f[i] == x) ans = i;
  }
  cout << ans;
  return 0;
}
