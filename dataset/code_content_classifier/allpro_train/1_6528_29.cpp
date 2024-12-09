#include <bits/stdc++.h>
using namespace std;
int Edge[1010][1010];
int Connect1[5010];
int Connect2[5010];
void add(int u, int v) {
  Edge[u][v] = 1;
  Edge[v][u] = 1;
}
int main() {
  int N;
  cin >> N;
  bitset<31> bits(N);
  int node = 2;
  int parent = 0;
  for (int i = 1; i <= 30; i++) {
    int u = node++, v = node++;
    add(parent, v), add(parent, u);
    int z = node++;
    add(v, z), add(u, z);
    Connect1[i] = z;
    parent = z;
  }
  for (int i = 0; i <= 30; i++) {
    Connect2[i] = node;
    add(node, node + 1), node += 1;
    add(node, node + 1), node += 1;
  }
  add(node++, 1);
  for (int i = 0; i < 31; i++) {
    if (bits[i]) {
      add(Connect2[i], Connect1[i]);
    }
  }
  cout << node << endl;
  for (int i = 0; i < node; i++) {
    for (int j = 0; j < node; j++) {
      if (Edge[i][j])
        cout << 'Y';
      else
        cout << 'N';
    }
    cout << endl;
  }
  return 0;
}
