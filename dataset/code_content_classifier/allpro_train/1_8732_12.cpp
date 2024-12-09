#include<cstdio>
#include<algorithm>
using namespace std;

int main(){
  int l,a,b,c,d;
  scanf("%d %d %d %d %d",&l,&a,&b,&c,&d);
  int x = (a+c-1)/c;
  x = max(x,(b+d-1)/d);
  printf("%d\n",l-x);
  return 0;
}