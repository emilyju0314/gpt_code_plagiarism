#include <cstdio>
#include <algorithm>
int main(){int n,S,r[10000];while(scanf("%d%d",&n,&S),n){for(int i=0;i<n;i++){scanf("%d",r+i);}std::sort(r,r+n);int res = 0;for(int i=0;i+1<n;i++){res += std::distance(std::upper_bound(r+i+1,r+n,S-r[i]),r+n);}printf("%d\n",res);}}