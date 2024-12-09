#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <complex>
#include <string.h>
#include <vector>
#include <queue>

using namespace std;
typedef complex<double> Complex;
typedef Complex Line[2];
typedef vector<Complex> Polygon;

static const double EPS = 1e-8;

inline double dot(const Complex &a, const Complex &b) {
  return real(conj(a) * b);
}

inline Complex projection(const Line &l, const Complex &p) {
  double t = dot(p - l[0], l[0] - l[1]) / norm(l[0] - l[1]);
  return l[0] + t * (l[0] - l[1]);
}

inline bool intersectSP(const Line &s, const Complex &p) {
  return abs(s[0] - p) + abs(s[1] - p) - abs(s[1] - s[0]) < EPS;
}

inline double distanceSP(const Line &s, const Complex &p)  {
  const Complex r = projection(s, p);
  if (intersectSP(s, r)) { return abs(r - p); }
  return min(abs(s[0] - p), abs(s[1] - p));
}

double distanceSS(const Line &s, const Line &t) {
  return min(min(distanceSP(s, t[0]), distanceSP(s, t[1])),
             min(distanceSP(t, s[0]), distanceSP(t, s[1])));
}

double distancePP(const Polygon &p1, const Polygon &p2) {
  double len = 100000000000.0;
  Line l1;
  Line l2;
  for (int i = 0; i < (int)p1.size(); i++) {
    l1[0] = p1[i];
    l1[1] = p1[0];
    if (i != (int)p1.size() - 1) { l1[1] = p1[i + 1]; }
    for (int j = 0; j < (int)p2.size(); j++) {
      l2[0] = p2[j];
      l2[1] = p2[0];
      if (j != (int)p2.size() - 1) { l2[1] = p2[j + 1]; }
      len = min(len, distanceSS(l1,  l2));
    }
  }
  return len;
}

struct Node {
  int where;
  double cost;
  Node(int w, double c) : where(w), cost(c) {;}
  bool operator<(const Node &rhs) const { return cost > rhs.cost; }
};

int width;
int n;
Polygon pillar[210];
bool check[210];
double dist[210];

double matrix[210][210];

inline int SOURCE() { return n; }
inline int DESTINATION() { return n + 1; }
inline int SIZE() { return n + 2; }

void print_matrix() {
  for (int i = 0; i < SIZE(); i++) {
    for (int j = 0; j < SIZE(); j++) {
      cout << matrix[i][j] << " ";
    }
    cout << endl;
  }
  cout << endl;
}

int main() {
  while (scanf("%d %d", &width, &n), width) {
  for (int i = 0; i < 210; i++) { pillar[i].clear(); }
  for (int i = 0; i < n; i++) {
    int size;
    scanf("%d", &size);
    for (int j = 0; j < size; j++) {
      int a, b;
      scanf("%d %d", &a, &b);
      pillar[i].push_back(Complex(a, b));
    }
  }
  pillar[SOURCE()].push_back(Complex(0, 0));
  pillar[SOURCE()].push_back(Complex(0, 100000));
  pillar[DESTINATION()].push_back(Complex(width, 0));
  pillar[DESTINATION()].push_back(Complex(width, 100000));
  for (int i = 0; i < SIZE(); i++) {
    check[i] = false;
    dist[i] = 100000000000000.0;
    for (int j = i; j < SIZE(); j++) {
      if (i == j) { matrix[i][j] = 0.0; continue; }
      matrix[i][j] = distancePP(pillar[i], pillar[j]);
      matrix[j][i] = matrix[i][j];
    }
  }
  priority_queue<Node> que;
  que.push(Node(SOURCE(), 0.0));
  while (!que.empty()) {
    Node node = que.top();
    que.pop();
    if (check[node.where]) { continue; }
    //cout << node.where << " " << node.cost << endl;
    check[node.where] = true;
    dist[node.where] = node.cost;
    if (node.where == DESTINATION()) { break; }
    for (int i = 0; i < SIZE(); i++) {
      double ncost = node.cost + matrix[node.where][i];
      if (check[i] || dist[i] < ncost) { continue; }
      dist[i] = ncost;
      que.push(Node(i, ncost));
    }
  }
  printf("%.6lf\n", dist[DESTINATION()]);
}
}