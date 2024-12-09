#include <bits/stdc++.h>
using namespace std;
const int maxN = 1000;
const int key = 701;
int n;
int perm[maxN];
int weight[maxN];
vector<pair<int, int> > edges;
int height[maxN];
map<int, int> saved;
set<int> parents[maxN];
int BS[maxN], CENT[maxN], PAR[maxN];
int get_hash(int v, vector<int> a, vector<int> b) {
  int hash = v;
  for (auto i : a) hash = hash * key + i;
  for (auto j : b) hash = hash * key + j;
  return hash;
}
int query(int v, vector<int> a, vector<int> b) {
  int hash = get_hash(v, a, b);
  if (saved.count(hash)) return saved[hash];
  cout << (int)a.size() << endl;
  for (int i = 0; i < (int)a.size(); i++) cout << (i ? " " : "") << perm[a[i]];
  cout << endl;
  cout << (int)b.size() << endl;
  for (int i = 0; i < (int)b.size(); i++) cout << (i ? " " : "") << perm[b[i]];
  cout << endl;
  cout << perm[v] << endl;
  cout.flush();
  int ans;
  cin >> ans;
  saved[hash] = ans;
  return ans;
}
int find_center(vector<int> &vertices, int H = 0) {
  if ((int)vertices.size() <= 2) return vertices[0];
  vector<int> ans;
  CENT[H] += (int)vertices.size();
  vector<int> first(vertices.begin(),
                    vertices.begin() + (int)vertices.size() / 2);
  vector<int> second(vertices.begin() + (int)vertices.size() / 2,
                     vertices.end());
  for (auto x : vertices) ans.push_back(query(x, first, second));
  return vertices[max_element(ans.begin(), ans.end()) - ans.begin()];
}
void find_tree(int v, vector<int> &vertices) {
  vector<int> can;
  vector<vector<int> > members;
  int deg = 0;
  for (auto i : vertices)
    if (i != v) {
      int s = 0, e = deg;
      if (e > s) BS[height[v]]++;
      if (e > s && query(v, {i}, can) < (int)(can.size())) {
        while (e - s > 1) {
          int mid = (e + s) / 2;
          BS[height[v]]++;
          if (query(v, {i}, vector<int>(can.begin() + s, can.begin() + mid)) ==
              mid - s)
            s = mid;
          else
            e = mid;
        }
        members[s].push_back(i);
      } else {
        can.push_back(i);
        members.push_back({i});
        deg++;
      }
    }
  for (int j = 0; j < deg; j++) {
    int u = find_center(members[j], height[v] + 1);
    set<int> copy(parents[v]);
    for (auto parent : copy) {
      PAR[height[v]]++;
      if (query(v, {parent}, members[j]) < (int)members[j].size())
        parents[v].erase(parent), parents[u].insert(parent);
    }
    parents[u].insert(v);
    height[u] = height[v] + 1;
    find_tree(u, members[j]);
  }
  for (auto parent : parents[v]) edges.push_back(pair<int, int>(v, parent));
}
int main() {
  srand(time(NULL));
  cin >> n;
  iota(perm, perm + n, 1);
  random_shuffle(perm, perm + n);
  vector<int> v(n);
  iota(v.begin(), v.end(), 0);
  find_tree(find_center(v), v);
  cout << "ANSWER" << endl;
  for (auto edge : edges)
    cout << perm[edge.first] << ' ' << perm[edge.second] << endl;
  cout.flush();
  return 0;
}
