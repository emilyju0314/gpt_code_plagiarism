#include <bits/stdc++.h>
using namespace std;
template <class C>
void mini(C &a4, C b4) {
  a4 = min(a4, b4);
}
template <class C>
void maxi(C &a4, C b4) {
  a4 = max(a4, b4);
}
template <class TH>
void _dbg(const char *sdbg, TH h) {
  cerr << sdbg << "=" << h << "\n";
}
template <class TH, class... TA>
void _dbg(const char *sdbg, TH h, TA... a) {
  while (*sdbg != ',') cerr << *sdbg++;
  cerr << "=" << h << ",";
  _dbg(sdbg + 1, a...);
}
template <class T>
ostream &operator<<(ostream &os, vector<T> V) {
  os << "[";
  for (auto v : V) os << v << ",";
  return os << "]";
}
template <class L, class R>
ostream &operator<<(ostream &os, pair<L, R> P) {
  return os << "(" << P.first << "," << P.second << ")";
}
set<string> reserved;
long long max_reserved;
vector<string> Parse(string s) {
  const long long len = ((long long)(s).size());
  s += " ";
  long long ptr = 0;
  vector<string> tokens;
  while (ptr < len) {
    if (s[ptr] == ' ') {
      ++ptr;
      continue;
    }
    string max_res;
    for (long long tlen = 1; tlen <= max_reserved && ptr + tlen <= len;
         ++tlen) {
      const string token_opt = s.substr(ptr, tlen);
      if (reserved.count(token_opt)) max_res = token_opt;
    }
    string token;
    long long old_ptr = ptr;
    if (isdigit(s[ptr])) {
      while (isdigit(s[ptr])) {
        token += s[ptr];
        ++ptr;
      }
    } else if (isalpha(s[ptr]) || s[ptr] == '_' || s[ptr] == '$') {
      while (isalnum(s[ptr]) || s[ptr] == '_' || s[ptr] == '$') {
        token += s[ptr];
        ++ptr;
      }
    }
    if (((long long)(max_res).size()) > ((long long)(token).size()))
      token = max_res;
    if (((long long)(token).size()) == 0) return {};
    tokens.push_back(token);
    ptr = old_ptr + ((long long)(token).size());
  }
  return tokens;
}
string code;
void Input() {
  long long N, M;
  cin >> N;
  for (long long i = 0; i < N; ++i) {
    string s;
    cin >> s;
    reserved.insert(s);
    maxi(max_reserved, ((long long)(s).size()));
  }
  cin >> M;
  string line;
  while (getline(cin, line)) {
    long long ptr = 0;
    while (ptr < ((long long)(line).size()) && line[ptr] != '#' &&
           line[ptr] != '\n' && line[ptr] != '\r')
      ++ptr;
    line = line.substr(0, ptr);
    code += line + " ";
  }
}
vector<string> names;
void AddName(string s) {
  if (!reserved.count(s)) names.push_back(s);
}
void GenNames() {
  for (char a = 'a'; a <= 'z'; ++a) {
    const string sa(1, a);
    AddName(sa);
    for (char b = 'a'; b <= 'z'; ++b) {
      AddName(sa + b);
      for (char c = 'a'; c <= 'z'; ++c) {
        AddName(sa + b + c);
      }
    }
  }
  sort((names).begin(), (names).end(),
       [&](const string &lhs, const string &rhs) {
         return make_pair(((long long)(lhs).size()), lhs) <
                make_pair(((long long)(rhs).size()), rhs);
       });
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  if (0) cout << fixed << setprecision(6);
  Input();
  (vector<string>((reserved).begin(), (reserved).end()), code);
  vector<string> tokens = Parse(code);
  assert(((long long)(tokens).size()) > 0);
  (tokens);
  string out;
  map<string, string> var_mapping;
  vector<long long> last_starts;
  vector<string> out_tokens;
  long long name_ptr = 0;
  GenNames();
  for (string token : tokens) {
    const bool is_name = !reserved.count(token) && !isdigit(token[0]);
    string new_name;
    if (is_name) {
      if (var_mapping.count(token)) {
        new_name = var_mapping[token];
      } else {
        new_name = names[name_ptr++];
        var_mapping[token] = new_name;
      }
    } else {
      new_name = token;
    }
    bool needs_space = false;
    long long sptr = ((long long)(last_starts).size()) - 1;
    bool next_break = false;
    while (sptr >= 0) {
      const long long pos = last_starts[sptr];
      const string check = out.substr(pos) + new_name;
      if (((long long)(check).size()) - ((long long)(new_name).size()) - 6 >
          max_reserved) {
        next_break = true;
      }
      auto parse_nospace = Parse(check);
      vector<string> expected;
      for (long long i = sptr; i < ((long long)(last_starts).size()); ++i)
        expected.push_back(out_tokens[i]);
      expected.push_back(new_name);
      if (expected != parse_nospace) {
        needs_space = true;
        break;
      }
      if (next_break) {
        break;
      }
      --sptr;
    }
    if (needs_space) out += " ";
    out_tokens.push_back(new_name);
    last_starts.push_back(((long long)(out).size()));
    out += new_name;
  }
  cout << out << "\n";
}
