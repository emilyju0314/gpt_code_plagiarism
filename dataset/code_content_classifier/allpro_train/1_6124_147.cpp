#include<bits/stdc++.h>
#define MAX 10005
using namespace std;
 
int main(){
  int d, g, p[10], c[10], i, j, ans = 1005, cnt, scr, b;
  scanf("%d%d", &d, &g);
  g /= 100;
  for(i = 0; i < d; i++){
    scanf("%d%d", &p[i], &c[i]);
    c[i] /= 100;
  }
  for(i = 0; i < 1<<d; i++){
    cnt = 0; scr = 0; b = 0;
    for(j = 0; j < d; j++){
      if(i&(1<<j)){
        scr += (j+1)*p[j] + c[j];
        cnt += p[j];
      }else b = j;
    }
    if(scr < g){
      if(scr + (b+1)*(p[b]-1) < g) continue;
      cnt += (g - scr - 1) / (b+1) +1;
    }
    ans = min(cnt, ans);
  }
  printf("%d\n", ans);
}
