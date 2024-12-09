#include <bits/stdc++.h>
using namespace std;
long long *arr;
class Graph {
  long long V;
  list<long long> *adj;
  list<long long> *adj2;
  long long DFSUtil(long long v, bool visited[]);

 public:
  Graph(long long V);
  void addEdge(long long v, long long w, long long id);
  void DFS(long long v);
};
Graph::Graph(long long V) {
  this->V = V;
  adj = new list<long long>[V];
  adj2 = new list<long long>[V];
}
void Graph::addEdge(long long v, long long w, long long id) {
  adj[v].push_back(w);
  adj2[v].push_back(id);
}
long long Graph::DFSUtil(long long v, bool visited[]) {
  visited[v] = true;
  long long sum = 1;
  list<long long>::iterator i;
  list<long long>::iterator i1 = adj2[v].begin();
  for (i = adj[v].begin(); i != adj[v].end(); ++i) {
    if (!visited[*i]) {
      long long x1 = DFSUtil(*i, visited);
      sum = sum + x1;
      arr[*i1] = x1;
    }
    ++i1;
  }
  return sum;
}
void Graph::DFS(long long v) {
  bool *visited = new bool[V];
  for (long long i = 0; i < V; i++) visited[i] = false;
  DFSUtil(v, visited);
}
int main() {
  long long n;
  cin >> n;
  arr = new long long[n - 1];
  Graph g(n);
  vector<long long> a1;
  vector<long long> b1;
  vector<long long> l1;
  for (long long i = 0; i < n - 1; ++i) {
    arr[i] = 0;
    long long a, b, l;
    cin >> a >> b >> l;
    a1.push_back(a);
    b1.push_back(b);
    l1.push_back(l);
    g.addEdge(a - 1, b - 1, i);
    g.addEdge(b - 1, a - 1, i);
  }
  g.DFS(0);
  double ans = 0;
  for (long long i = 0; i < n - 1; ++i) {
    long long wt = 0;
    long long n1 = arr[i];
    long long n2 = n - arr[i];
    wt = 6 * (n1 * n2 * (n2 - 1) + n2 * (n1) * (n1 - 1));
    ans = ans + l1[i] * wt;
    arr[i] = wt;
  }
  long long q;
  cin >> q;
  double div = n * (n - 1) * (n - 2);
  for (long long i = 0; i < q; ++i) {
    long long r, w1;
    cin >> r >> w1;
    double ans1 = (ans - (l1[r - 1] - w1) * arr[r - 1]);
    printf("%lf\n", ans1 / div);
    l1[r - 1] = w1;
    ans = ans1;
  }
}
