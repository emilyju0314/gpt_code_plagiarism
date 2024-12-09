//  It is not in the stars to hold our destiny, but in ourselves.

#include <bits/stdc++.h>
using namespace std;
#define max(a, b) (a < b ? b : a)
#define min(a, b) ((a > b) ? b : a)
#define mod 1e9 + 7
#define FOR(a, c) for ((a) = 0; (a) < (c); (a)++)
#define FORL(a, b, c) for ((a) = (b); (a) <= (c); (a)++)
#define FORR(a, b, c) for ((a) = (b); (a) >= (c); (a)--)
#define INF 1000000000000000003
typedef long long int ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define F first
#define S second
#define PB push_back
#define POB pop_back
#define MP make_pair
#define endl cout << endl
#define scani(a) scanf("%d", &a);
#define scanii(a, b) scanf("%d %d", &a, &b);
#define scaniii(a, b, c) scanf("%d %d %d", &a, &b, &c);
#define scanll(a) scanf("%lld", &a);
#define scanc(a) scanf("%c", &a);
#define printi(a) printf("%d ", a);
#define printll(a) printf("%lld ", a);
#define printc(a) printf("%c ", a);

int main() {
  ll t, n, i, p;
  cin >> t;
  while (t--) {
    cin >> n;
    p = floor(log2f(n));
    cout << (ll)pow(2, p) - 1;
    endl;
  }
  return 0;
}