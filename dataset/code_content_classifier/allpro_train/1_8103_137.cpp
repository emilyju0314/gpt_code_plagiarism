#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> crush, cyc_nodes;
vector<int> vis;
bool crossover = false;
bool findcycs() {
  int vis_n = 1, j, nodes;
  for (int i = 0; i < n; i++) {
    if (vis[i] > 0) continue;
    nodes = 0;
    j = i;
    while (vis[j] == 0) {
      vis[j] = vis_n;
      nodes++;
      j = crush[j];
      if (vis[j] > 0 && j != i) {
        crossover = true;
        return false;
      }
    }
    vis_n++;
    if (nodes % 2 == 0) nodes /= 2;
    cyc_nodes.push_back(nodes);
  }
  return true;
}
int gcd(int a, int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
int findlcm(vector<int> arr) {
  int ans = arr[0];
  for (int i = 1; i < arr.size(); i++)
    ans = (((arr[i] * ans)) / (gcd(arr[i], ans)));
  return ans;
}
int main() {
  cin >> n;
  crush.resize(n);
  vis.resize(n);
  int ele;
  for (int i = 0; i < n; i++) {
    cin >> ele;
    crush[i] = ele - 1;
  }
  if (!findcycs()) {
    cout << -1;
  } else {
    cout << findlcm(cyc_nodes);
  }
}
