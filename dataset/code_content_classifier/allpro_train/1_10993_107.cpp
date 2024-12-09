#include <bits/stdc++.h>

using namespace std;

#define int long long
#define all(v) begin(v), end(v)
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define reps(i, s, n) for(int i = (int)(s); i < (int)(n); i++)

const int inf = 1LL << 55;
const int mod = 1e9 + 7;

string s;
int idx;

char up(char c)
{
  if(c == 'Z') c = 'A';
  else if(c != '?') c = (char)(c + 1);
  return c;
}

char down(char c)
{
  if(c == 'A') c = 'Z';
  else if(c != '?') c = (char)(c - 1);
  return c;
}

char get()
{
  if(s[idx] == '+') { idx++; return up(get()); }
  if(s[idx] == '-') { idx++; return down(get()); }
  return s[idx];
}

string solve(bool rev)
{
  string ret = "";
  for(; idx < s.size(); idx++) {
    if(s[idx] == '[') idx++, ret += solve(true);
    else if(s[idx] == ']') {
      reverse(all(ret));
      return ret;
    }
    else ret += get();
  }
  return ret;
}

signed main()
{
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(12);

  while(cin >> s, s != ".") {
    idx = 0;
    string ans = solve(false);
    replace(all(ans), '?', 'A');
    cout << ans << endl;
  }

  return 0;
}