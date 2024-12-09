#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
  for(int tci = 0; ; tci++) {
    int V, d;
    if(scanf("%d%d", &V, &d)<2) break;
    static int fbnt[2000];
    int x=1,y=2;
    for(int i = 0; i < V; i++) {
      fbnt[i] = y;
      int z = (x+y)%1001;
      x = y;
      y = z;
    }
    sort(fbnt,fbnt+V);
    int grp_cnt = 1;
    for(int i = 1; i < V; i++) {
      if(fbnt[i]-fbnt[i-1]>=d) grp_cnt++;
    }
    printf("%d\n", grp_cnt);
  }
  return 0;
}