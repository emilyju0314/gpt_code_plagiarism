#include <cstdio>
#include <algorithm>

int main(){
  int A,B;
  scanf("%d %d",&A,&B);
  printf("%d\n",std::max(A+B,std::max(A-B,A*B)));
}
