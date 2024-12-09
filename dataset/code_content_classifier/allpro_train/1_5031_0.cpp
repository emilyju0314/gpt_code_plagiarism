#include <bits/stdc++.h>
using namespace std;
const long long maxn = 1e5 + 10;
ifstream input;
ofstream output;
long long n;
pair<long long, long long> a[maxn];
pair<pair<long long, long long>, long long> b[maxn], c[maxn];
int32_t main() {
  input.open("input.txt");
  output.open("output.txt");
  if (!input) {
    cout << -1 << endl;
    return 0;
  }
  input >> n;
  for (long long i = 0; i < n; i++) {
    long long x, y;
    input >> x >> y;
    b[i] = {{abs(x), abs(y)}, i};
    c[i] = {{abs(y), abs(x)}, i};
    a[i] = {x, y};
  }
  long long pos;
  long long pos1;
  long long ans = 1e12;
  sort(b, b + n);
  for (long long i = 0; i < n; i++) {
    long long j = 1;
    while (i + j < n && j < 200) {
      long long x = abs(b[i + j].first.first - b[i].first.first);
      long long y = abs(b[i + j].first.second - b[i].first.second);
      long long t_ans = x * x + y * y;
      if (ans > t_ans) {
        ans = t_ans;
        pos = b[i].second;
        pos1 = b[i + j].second;
      }
      j++;
    }
  }
  long long x1 = a[pos].first;
  long long y1 = a[pos].second;
  long long x2 = a[pos1].first;
  long long y2 = a[pos1].second;
  output << pos + 1 << ' ';
  if (x1 > 0 && y1 > 0) {
    output << 1;
  } else if (x1 > 0 && y1 < 0) {
    output << 3;
  } else if (x1 < 0 && y1 > 0) {
    output << 2;
  } else {
    output << 4;
  }
  output << ' ' << pos1 + 1 << ' ';
  if (x2 > 0 && y2 > 0) {
    output << 4;
  } else if (x2 > 0 && y2 < 0) {
    output << 2;
  } else if (x2 < 0 && y2 > 0) {
    output << 3;
  } else {
    output << 1;
  }
  output << "\n";
  output.close();
  input.close();
}
