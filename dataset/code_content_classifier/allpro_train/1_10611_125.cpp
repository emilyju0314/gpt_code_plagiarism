#include <bits/stdc++.h>
using namespace std;
bool size_cmp(vector<int> a, vector<int> b) { return a.size() < b.size(); }
int main() {
  int n;
  cin >> n;
  vector<int> permutation(n);
  vector<int> root_permutation(n);
  for (int i = 0; i < n; ++i) {
    cin >> permutation[i];
  }
  vector<vector<int> > cycles;
  vector<vector<int> > even_cycles;
  vector<bool> visited(n, false);
  for (int i = 0; i < n; ++i) {
    if (!visited[i]) {
      visited[i] = true;
      cycles.push_back(vector<int>());
      cycles.back().push_back(i);
      int j = permutation[i] - 1;
      while (j != i) {
        visited[j] = true;
        cycles.back().push_back(j);
        j = permutation[j] - 1;
      }
    }
  }
  for (vector<vector<int> >::iterator i = cycles.begin(); i != cycles.end();
       ++i) {
    int l = i->size();
    if (l % 2 == 1) {
      for (int j = 0; j < l; ++j) {
        root_permutation[(*i)[j]] = (*i)[((l >> 1) + j + 1) % l] + 1;
      }
    } else {
      even_cycles.push_back(*i);
    }
  }
  if (even_cycles.size() % 2) {
    cout << -1;
    return 0;
  }
  sort(even_cycles.begin(), even_cycles.end(), size_cmp);
  for (vector<vector<int> >::iterator i = even_cycles.begin();
       i != even_cycles.end(); i += 2) {
    int l = i->size();
    if ((i + 1)->size() > l) {
      cout << -1;
      return 0;
    } else {
      for (int j = 0; j < l; ++j) {
        root_permutation[(*i)[j]] = (*(i + 1))[j] + 1;
        root_permutation[(*(i + 1))[j]] = (*i)[(j + 1) % l] + 1;
      }
    }
  }
  for (int i = 0; i < n; ++i) {
    printf("%d ", root_permutation[i]);
  }
  return 0;
}
