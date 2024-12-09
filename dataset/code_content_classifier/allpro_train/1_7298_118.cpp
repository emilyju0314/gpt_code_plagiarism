#include <bits/stdc++.h>
using namespace std;
struct Match_Container {
  int a, b;
};
bool compare_match_containers(const Match_Container& c1,
                              const Match_Container& c2) {
  return c1.b > c2.b;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, m, ctr(0), ctr2(0);
  Match_Container m_container;
  vector<Match_Container> v;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < m; i++) {
    scanf("%d %d", &m_container.a, &m_container.b);
    v.push_back(m_container);
  }
  sort(v.begin(), v.end(), compare_match_containers);
  int diff;
  for (int i = 0; i < v.size(); i++) {
    if ((ctr2 + v[i].a) > n) {
      ctr += (n - ctr2) * v[i].b;
      break;
    } else {
      ctr += v[i].a * v[i].b;
      ctr2 += v[i].a;
    }
  }
  cout << ctr << endl;
  return 0;
}
