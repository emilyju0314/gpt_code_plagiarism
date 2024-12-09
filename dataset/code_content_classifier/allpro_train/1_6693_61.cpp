#include <bits/stdc++.h>
using namespace std;
struct segment_tree {
  int n;
  int pow2;
  int* A;
  segment_tree(int _n) {
    n = _n;
    pow2 = 1;
    while (pow2 < n) pow2 <<= 1;
    A = new int[pow2 * 2];
    for (int i = 0; i < n; i++) A[i + pow2] = 1;
    for (int i = n + pow2; i < (pow2 << 1); i++) A[i] = 0;
    for (int i = pow2 - 1; i >= 1; i--) A[i] = A[i << 1] + A[(i << 1) + 1];
  }
  void update(int ind, int val) {
    ind += pow2;
    A[ind] = val;
    while (ind > 1) {
      ind >>= 1;
      A[ind] = A[ind << 1] + A[(ind << 1) + 1];
    }
  }
  int next_ind(int i) {
    if (A[pow2 + i] == 1) return i;
    int goal;
    if (sum(i, n - 1) == 0) {
      goal = 1;
    } else {
      goal = sum(0, i) + 1;
    }
    int ind = 1;
    while (ind < pow2) {
      if (A[ind << 1] >= goal)
        ind = ind << 1;
      else {
        goal -= A[ind << 1];
        ind = (ind << 1) + 1;
      }
    }
    return ind - pow2;
  }
  int sum(int L, int R) { return sum(L, R, 1, 0, pow2 - 1); }
  int sum(int L, int R, int ind, int LB, int RB) {
    if (L > R) return 0;
    if (LB == L && R == RB) return A[ind];
    int MB = (LB + RB) >> 1;
    return sum(L, min(MB, R), ind << 1, LB, MB) +
           sum(max(MB + 1, L), R, (ind << 1) + 1, MB + 1, RB);
  }
  ~segment_tree() { delete[] A; }
};
const int MX = 2 * 100 * 1000 + 9;
segment_tree* T[MX];
int chain_number[MX];
int chain_index[MX];
int chain_sizes[MX];
int chain_count;
int h, m, n;
void init_chains(void) {
  static bool marked[MX];
  for (int start = 0; start < h; start++) marked[start] = false;
  chain_count = 0;
  for (int start = 0; start < h; start++) {
    if (!marked[start]) {
      int current_sz = 0;
      int current_val = start;
      do {
        marked[current_val] = true;
        chain_number[current_val] = chain_count;
        chain_index[current_val] = current_sz;
        current_sz++;
        current_val += m;
        if (current_val >= h) current_val -= h;
      } while (current_val != start);
      T[chain_count] = new segment_tree(current_sz);
      chain_sizes[chain_count] = current_sz;
      chain_count++;
    }
  }
}
struct pos {
  int chain, index;
};
map<int, pos> M;
long long add(int id, int hsh) {
  int chain = chain_number[hsh];
  int index = chain_index[hsh];
  int next_ind = T[chain]->next_ind(index);
  T[chain]->update(next_ind, 0);
  pos result;
  result.chain = chain;
  result.index = next_ind;
  M[id] = result;
  long long ans;
  if (next_ind >= index)
    ans = next_ind - index;
  else
    ans = next_ind + chain_sizes[chain] - index;
  return ans;
}
void del(int id) {
  map<int, pos>::iterator it = M.find(id);
  pos p = it->second;
  M.erase(it);
  T[p.chain]->update(p.index, 1);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> h >> m >> n;
  init_chains();
  long long result = 0LL;
  char type;
  int id, hsh;
  for (int i = 0; i < n; i++) {
    cin >> type;
    if (type == '+') {
      cin >> id >> hsh;
      result += add(id, hsh);
    } else {
      cin >> id;
      del(id);
    }
  }
  cout << result;
  return 0;
}
