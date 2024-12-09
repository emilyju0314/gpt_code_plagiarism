#include <bits/stdc++.h>
using namespace std;
int n, m, color[int(1e5)], color_tmp[2][int(1e5)], color_chosen,
    res = int(1e9 + 7), cnt = 0, cnt_tmp, cnt_state, res_id[int(1e5)],
    res_id_tmp[int(1e5)], tt[int(1e5)];
vector<pair<int, int> > a[int(1e5)];
int visit[int(1e5)];
void init() {
  for (int i = 0; i < n; i++) {
    visit[i] = 0;
  }
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < m; j++) {
      color_tmp[i][j] = color[j];
    }
  }
  cnt = 0;
}
bool DFS(int x, int state, int id) {
  visit[x]++;
  if (state == 1) {
    res_id_tmp[cnt_state + cnt] = x + 1;
    cnt_state++;
  }
  for (vector<pair<int, int> >::iterator i = a[x].begin(); i < a[x].end();
       i++) {
    int v = i->first;
    int e = i->second;
    if (state == 1) {
      color_tmp[id][e] = 1 - color_tmp[id][e];
    }
    if (visit[v] == visit[x]) {
      if (color_tmp[id][e] != color_chosen) {
        return 0;
      }
    }
  }
  for (vector<pair<int, int> >::iterator i = a[x].begin(); i < a[x].end();
       i++) {
    int v = i->first;
    int e = i->second;
    if (visit[v] == visit[x]) continue;
    bool res_tmp = 1;
    int next_state = 0;
    if (color_tmp[id][e] != color_chosen) {
      next_state = 1;
    }
    res_tmp = DFS(v, next_state, id);
    if (res_tmp == 0) return 0;
  }
  return 1;
}
void sol() {
  bool tmp1;
  int ok, mark;
  for (color_chosen = 0; color_chosen <= 1; color_chosen++) {
    ok = 0;
    init();
    for (int i = 0; i < n; i++)
      if (visit[i] == 0) {
        cnt_tmp = int(1e9 + 7);
        ok = 0;
        mark = -1;
        for (int state = 0; state < 2; state++) {
          cnt_state = 0;
          tmp1 = DFS(i, state, state);
          if (tmp1 == 1) {
            if (cnt_tmp > cnt_state) {
              cnt_tmp = cnt_state;
              mark = state;
            }
            ok = 1;
          }
          if (state == 0) {
            for (int j = cnt; j <= cnt + cnt_state; j++) {
              tt[j] = res_id_tmp[j];
            }
          }
        }
        if (mark == 0) {
          for (int i = cnt; i <= cnt + cnt_tmp; i++) {
            res_id_tmp[i] = tt[i];
          }
        }
        cnt += cnt_tmp;
        if (ok == 0) break;
      }
    if (ok == 1) {
      if (res > cnt) {
        res = cnt;
        for (int i = 0; i < cnt; i++) {
          res_id[i] = res_id_tmp[i];
        }
      }
    }
  }
}
int main() {
  scanf("%d %d\n", &n, &m);
  for (int i = 0; i < m; i++) {
    char tmp;
    int u, v;
    pair<int, int> a_tmp;
    scanf("%d %d %c", &u, &v, &tmp);
    u--;
    v--;
    if (tmp == 'R') {
      color[i] = 0;
    }
    if (tmp == 'B') {
      color[i] = 1;
    }
    a_tmp = make_pair(v, i);
    a[u].push_back(a_tmp);
    a_tmp = make_pair(u, i);
    a[v].push_back(a_tmp);
  }
  sol();
  if (res < int(1e9 + 7)) {
    printf("%d\n", res);
    for (int i = 0; i < res; i++) {
      printf("%d ", res_id[i]);
    }
  } else {
    printf("-1");
  }
}
