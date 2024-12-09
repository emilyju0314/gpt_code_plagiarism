#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> ii;
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sqr(x) ((x) * (x))
#define X first
#define Y second
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR (i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define MAXN 200200

int n;
set<int> s;
vector<int> v;

void solve()
{
  s.clear();
  v.clear();
  scanf("%d", &n);
  for (int i = n; i > 2; i = ceil(sqrt(double(i)))) {
    s.insert(i);
    v.pb(i);
  }
  v.pb(2);
  s.insert(2);
  printf("%d\n", n - 1 - s.size() + 2 * (s.size() - 1));
  for (int i = 3; i <= n; i++) {
    if (!s.count(i)) {
      printf("%d %d\n", i, i + 1);
    }
  }
  for (int i = 0; i < v.size() - 1; i++) {
    printf("%d %d\n", v[i], v[i + 1]);
    printf("%d %d\n", v[i], v[i + 1]);
  }
}

int main()
{
  int t;
  scanf("%d", &t);
  while (t--) solve();
  return 0;
}
