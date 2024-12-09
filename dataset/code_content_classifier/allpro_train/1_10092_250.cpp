#include <bits/stdc++.h>
using namespace std;
int search(int ceil, vector<pair<int, int>> &bea) {
  int beg = 0;
  int end = bea.size() - 1;
  int result = end;
  while (beg <= end) {
    int mid = (beg + end) / 2;
    int pos = bea[mid].first;
    if (ceil == pos) return mid;
    if (pos < ceil) {
      result = pos;
      beg = mid + 1;
    } else {
      end = mid - 1;
    }
  }
  return result;
}
int main() {
  int size;
  cin >> size;
  vector<pair<int, int>> in(size);
  for (int i = 0; i < size; i++) {
    cin >> in[i].first >> in[i].second;
  }
  sort(in.begin(), in.end());
  vector<int> pos(1100000, 0);
  int index = 0;
  int result = 0;
  for (int i = 0; i < pos.size(); i++) {
    if (i == in[index].first) {
      int prev = in[index].first - in[index].second - 1;
      int add = 0;
      if (prev < 0)
        add = 0;
      else
        add = pos[prev];
      pos[i] = 1 + add;
      index++;
    } else {
      if (i == 0)
        pos[i] = 0;
      else {
        pos[i] = pos[i - 1];
      }
    }
    result = max(result, pos[i]);
  }
  cout << size - result;
}
