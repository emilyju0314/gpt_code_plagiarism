#include <bits/stdc++.h>
using namespace std;
void fast_io() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
}
void fill(int smaller, int larger, char root, vector<pair<int, int> > &coords) {
  int l_position = 0;
  int s_position = 0;
  int x_larger = (root == 'B') ? 2 : 1;
  int x_smaller = (root == 'B') ? 2 : 1;
  coords.push_back({x_larger, 1 + 1});
  x_larger++;
  larger--;
  while (larger != 0) {
    if (l_position == 0) {
      coords.push_back({x_larger, l_position + 1});
      larger--;
      coords.push_back({x_larger, l_position + 2});
      smaller--;
    } else {
      coords.push_back({x_larger, l_position + 2});
      larger--;
      if (larger != 0) {
        coords.push_back({x_larger + 1, l_position + 1});
        larger--;
      }
    }
    l_position++;
    l_position %= 2;
    if (l_position == 0) x_larger += 2;
  }
  while (smaller != 0) {
    if (s_position == 1) {
      coords.push_back({x_smaller, s_position + 2});
      x_smaller += 2;
    } else
      coords.push_back({x_smaller, s_position + 1});
    s_position++;
    s_position %= 2;
    smaller--;
  }
}
void fillLinear(int len, vector<pair<int, int> > &coords) {
  for (int i = 1; i <= (len << 1); i++) coords.push_back({i, 1});
}
void printSolution(vector<pair<int, int> > &coords) {
  cout << "YES" << '\n';
  for (int i = 0; i < coords.size(); i++)
    cout << coords[i].first << ' ' << coords[i].second << '\n';
}
int main() {
  fast_io();
  int tc;
  cin >> tc;
  while (tc--) {
    int B, W;
    vector<pair<int, int> > coords;
    cin >> B >> W;
    if ((B < W) and W <= (3 * B + 1))
      fill(B, W, 'B', coords);
    else if ((W < B) and B <= (3 * W + 1))
      fill(W, B, 'W', coords);
    else if (B == W)
      fillLinear(B, coords);
    else {
      cout << "NO" << '\n';
      continue;
    }
    printSolution(coords);
  }
  return 0;
}
