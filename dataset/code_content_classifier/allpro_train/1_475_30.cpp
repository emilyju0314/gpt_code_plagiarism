#include <bits/stdc++.h>
using namespace std;
class edge {
 public:
  int xx, yy, mode;
  bool operator<(const edge &ee) const { return xx < ee.xx; };
};
long long cnt[100001];
edge line[200001];
map<int, int> status;
map<int, int>::iterator it, sit, eit, jt;
map<int, int> now;
int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  for (int i = 0; i < n; i++) {
    scanf("%d %d", &(line[2 * i + 1].xx), &(line[2 * i].yy));
    line[2 * i].xx = line[2 * i + 1].xx - (k - 1);
    line[2 * i].mode = 1;
    line[2 * i + 1].xx++;
    line[2 * i + 1].yy = line[2 * i].yy;
    line[2 * i + 1].mode = -1;
  }
  status[-2100000000] = 0;
  sort(line, line + (2 * n));
  int prev = line[0].xx;
  for (int i = 0; i < 2 * n; i++) {
    if (prev != line[i].xx) {
      int nujeok = 0;
      it = status.begin();
      jt = it;
      jt++;
      for (; jt != status.end();) {
        nujeok += (*it).second;
        cnt[nujeok] += ((*jt).first - (*it).first) * (line[i].xx - prev);
        it++;
        jt++;
      }
    }
    if (status.find(line[i].yy - (k - 1)) == status.end())
      status[line[i].yy - (k - 1)] = 0;
    if (status.find(line[i].yy + 1) == status.end()) status[line[i].yy + 1] = 0;
    status[line[i].yy - (k - 1)] += line[i].mode;
    status[line[i].yy + 1] -= line[i].mode;
    if (status[line[i].yy - (k - 1)] == 0)
      status.erase(status.find(line[i].yy - (k - 1)));
    if (status[line[i].yy + 1] == 0) status.erase(status.find(line[i].yy + 1));
    prev = line[i].xx;
  }
  for (int i = 1; i <= n; i++) {
    printf("%lld ", cnt[i]);
  }
  printf("\n");
}
