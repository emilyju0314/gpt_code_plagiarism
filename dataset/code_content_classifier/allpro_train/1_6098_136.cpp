#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  int count, last;
  long long sums[] = {0, 0};
  vector<int> points[2];
  cin >> count;
  for (int counter = 0; counter < count; ++counter) {
    int input;
    cin >> input;
    last = input < 0;
    if (last) {
      input = -input;
    }
    sums[last] += input;
    points[last].push_back(input);
  }
  if (sums[0] < sums[1]) {
    cout << "second\n";
  } else if (sums[1] < sums[0]) {
    cout << "first\n";
  } else if (lexicographical_compare(points[0].begin(), points[0].end(),
                                     points[1].begin(), points[1].end())) {
    cout << "second\n";
  } else if (lexicographical_compare(points[1].begin(), points[1].end(),
                                     points[0].begin(), points[0].end())) {
    cout << "first\n";
  } else if (last) {
    cout << "second\n";
  } else {
    cout << "first\n";
  }
  return 0;
}
