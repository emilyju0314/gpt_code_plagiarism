#include <bits/stdc++.h>
using namespace std;
struct BLOCK {
  int id, outdegree;
  int x, y;
  vector<int> above;
  vector<int> below;
  bool alive;
  BLOCK() {}
  BLOCK(int id) : id(id) {
    alive = true;
    outdegree = 0;
  }
} block[100005];
int m;
int trans[100005];
const long long MOD = 1e9 + 9;
map<pair<int, int>, int> pos_to_id;
void preprocess() {
  for (int i = 0; i < m; ++i) {
    pair<int, int> now;
    now.first = block[i].x;
    now.second = block[i].y;
    pair<int, int> tmp = now;
    tmp.second--;
    if (pos_to_id.count(tmp) != 0) {
      ++block[i].outdegree;
      block[i].below.push_back(pos_to_id[tmp]);
      block[pos_to_id[tmp]].above.push_back(pos_to_id[now]);
    }
    --tmp.first;
    if (pos_to_id.count(tmp) != 0) {
      ++block[i].outdegree;
      block[i].below.push_back(pos_to_id[tmp]);
      block[pos_to_id[tmp]].above.push_back(pos_to_id[now]);
    }
    tmp.first += 2;
    if (pos_to_id.count(tmp) != 0) {
      ++block[i].outdegree;
      block[i].below.push_back(pos_to_id[tmp]);
      block[pos_to_id[tmp]].above.push_back(pos_to_id[now]);
    }
  }
}
bool cmp(const BLOCK& x, const BLOCK& y) {
  if (x.y > y.y) return true;
  if (x.y < y.y) return false;
  if (x.x < y.x) return true;
  if (x.x > y.x) return false;
  return false;
}
bool cmp2(const BLOCK& x, const BLOCK& y) { return x.id > y.id; }
void print() {
  cout << "===" << endl;
  for (int i = 0; i < m; ++i) {
    cout << block[i].id << " outdegree: " << block[i].outdegree << endl;
    for (int j = 0; j < block[i].above.size(); ++j) {
      cout << block[i].above[i] << " ";
    }
    cout << endl;
  }
  cout << "===" << endl;
}
bool availible(int block_code) {
  for (int i = 0; i < block[block_code].above.size(); ++i) {
    int target = trans[block[block_code].above[i]];
    if (!block[target].alive) continue;
    if (block[target].outdegree == 1) return false;
  }
  return true;
}
void take(int block_code, long long& ans,
          priority_queue<int, vector<int>, less<int> >& gpq,
          priority_queue<int, vector<int>, greater<int> >& lpq) {
  ans = (ans * m + block[block_code].id) % MOD;
  for (int i = 0; i < block[block_code].above.size(); ++i) {
    --block[trans[block[block_code].above[i]]].outdegree;
  }
  block[block_code].alive = false;
  for (int i = 0; i < block[block_code].below.size(); ++i) {
    int target = trans[block[block_code].below[i]];
    if (!block[target].alive) continue;
    if (availible(target)) {
      gpq.push(block[block_code].below[i]);
      lpq.push(block[block_code].below[i]);
    }
  }
}
void solve() {
  int last = m;
  long long ans = 0;
  priority_queue<int, vector<int>, less<int> > gpq;
  priority_queue<int, vector<int>, greater<int> > lpq;
  for (int i = 0; i < m; ++i) {
    if (availible(i)) {
      gpq.push(block[i].id);
      lpq.push(block[i].id);
    }
  }
  while (last) {
    while (gpq.size()) {
      int now = gpq.top();
      gpq.pop();
      int target = trans[now];
      if (!block[target].alive) continue;
      if (!availible(target)) continue;
      take(target, ans, gpq, lpq);
      break;
    }
    --last;
    if (last == 0) break;
    while (lpq.size()) {
      int now = lpq.top();
      lpq.pop();
      int target = trans[now];
      if (!block[target].alive) continue;
      if (!availible(target)) continue;
      take(target, ans, gpq, lpq);
      break;
    }
    --last;
  }
  cout << ans << endl;
}
void make_table() {
  for (int i = 0; i < m; ++i) {
    trans[block[i].id] = i;
  }
}
int main() {
  scanf("%d", &m);
  for (int i = 0; i < m; ++i) {
    block[i] = BLOCK(i);
    pair<int, int> tmp;
    scanf("%d%d", &tmp.first, &tmp.second);
    block[i].x = tmp.first;
    block[i].y = tmp.second;
    pos_to_id[tmp] = i;
  }
  preprocess();
  sort(block, block + m, cmp2);
  make_table();
  solve();
  return 0;
}
