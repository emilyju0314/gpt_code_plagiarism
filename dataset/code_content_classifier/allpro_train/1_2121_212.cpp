#include <bits/stdc++.h>
using namespace std;
const bool testing = false;
class Graph {
  multiset<pair<int, int>> edges;
  multiset<pair<int, int>> redges;

 public:
  void add(int a, int b) {
    if (a > b) {
      add(b, a);
      return;
    }
    redges.insert(pair<int, int>(b, a));
    edges.insert(pair<int, int>(a, b));
  }
  void remove(int a, int b) {
    if (a > b) {
      remove(b, a);
      return;
    }
    pair<int, int> p;
    multiset<pair<int, int>>::iterator i = redges.find(pair<int, int>(b, a));
    redges.erase(i);
    i = edges.find(pair<int, int>(a, b));
    edges.erase(i);
  }
  int findanyneighbour(int a) {
    multiset<pair<int, int>>::iterator i =
        redges.lower_bound(pair<int, int>(a, -1));
    if (i != redges.end() && i->first == a) return i->second;
    i = edges.lower_bound(pair<int, int>(a, -1));
    if (i != edges.end() && i->first == a) return i->second;
    return -1;
  }
  void findEuler(int c, list<int>& r) {
    int n;
    while ((n = findanyneighbour(c)) != -1) {
      remove(c, n);
      findEuler(n, r);
    }
    r.push_front(c);
  }
};
void program() {
  int n, m;
  cin >> n >> m;
  vector<int> d(n + 1);
  Graph g;
  int ec = 0;
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    d[a]++;
    d[b]++;
    g.add(a, b);
    ec++;
  }
  int p = -1;
  for (int i = 0; i <= n; i++) {
    if (d[i] % 2 == 1) {
      if (p == -1) {
        p = i;
      } else {
        g.add(p, i);
        ec++;
        p = -1;
      }
    }
  }
  if (ec % 2 == 1) {
    g.add(1, 1);
    ec++;
  }
  cout << ec << endl;
  list<int> e;
  g.findEuler(1, e);
  {
    bool dir = true;
    list<int>::const_iterator i = e.cbegin();
    int prev = *i;
    i++;
    for (; i != e.cend();) {
      if (dir) {
        cout << prev << " " << *i << endl;
      } else {
        cout << *i << " " << prev << endl;
      }
      dir = !dir;
      prev = *i;
      i++;
    }
  }
}
int main() {
  if (!testing) {
    program();
    return 0;
  }
  FILE* fin = NULL;
  fin = fopen("in.txt", "w+");
  fprintf(fin, "4 6\n1 2\n2 3\n3 4\n4 1\n1 3\n1 3\n");
  fclose(fin);
  freopen("in.txt", "r", stdin);
  printf("test case(1) => expected : \n");
  printf("6\n1 2\n3 4\n1 4\n3 2\n1 3\n1 3");
  printf("test case(1) => founded  : \n");
  program();
  fin = fopen("in.txt", "w+");
  fprintf(fin, "3 4\n1 2\n2 3\n1 1\n3 3\n");
  fclose(fin);
  freopen("in.txt", "r", stdin);
  printf("test case(2) => expected : \n");
  printf("6\n2 1\n2 3\n1 1\n3 3\n3 1\n1 1\n");
  printf("test case(2) => founded  : \n");
  program();
  return 0;
}
