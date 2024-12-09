#include <iostream>

using namespace std;
typedef long long ll;

int main()
{
  ll x, y;
  cin >> x >> y;
  ll ans = 1000000000000LL;
  if(y - x >= 0) ans = min(ans, y - x);
  if(y - (-x) >= 0) ans = min(ans, y + x + 1);
  if((-y) - x >= 0) ans = min(ans, -y - x + 1);
  if((-y) - (-x) >= 0) ans = min(ans, -y + x + 2);
  cout << ans << endl;
}
