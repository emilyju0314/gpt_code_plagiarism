#include <bits/stdc++.h>
using namespace std;
const double pi = acos(-1.0);
const int inf = 10000000;
long long tree[1000005];
int arr[100005];
void update(int x, long long v) {
  for (; x < 1000005; x += x & -x) tree[x] = (tree[x] + v) % 1000000007ll;
}
long long read(int x) {
  long long sum = 0;
  for (; x; x -= x & -x) sum = (sum + tree[x]) % 1000000007ll;
  return sum;
}
int main() {
  int n;
  cin >> n;
  int x;
  long long t, v;
  for (int i = 0; i < (n); i++) {
    scanf("%d", &x);
    t = (read(x) + 1) * x;
    v = read(x) - read(x - 1);
    v %= 1000000007ll;
    v += 1000000007ll;
    v %= 1000000007ll;
    t -= v;
    t %= 1000000007ll;
    t += 1000000007ll;
    t %= 1000000007ll;
    update(x, t);
  }
  printf("%d\n", (int)read(1000005 - 1));
  return 0;
}
