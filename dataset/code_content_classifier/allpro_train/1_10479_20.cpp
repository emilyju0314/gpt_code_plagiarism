#include<bits/stdc++.h>
using namespace std;
typedef complex<double> P;
 
P calc(P a,P b,P c,P d){
  a-=d;b-=d;c-=d;
  return d+a+(b-a)*imag(a/c)/(imag((a-b)/c));
}
 
int main(){
  int n;
  double ax,ay,bx,by,cx,cy,dx,dy;
  scanf("%d",&n);
  while(n--){
    scanf("%lf %lf %lf %lf %lf %lf %lf %lf",&ax,&ay,&bx,&by,&cx,&cy,&dx,&dy);
    P ans=calc(P(ax,ay),P(bx,by),P(cx,cy),P(dx,dy));
    printf("%.8f %.8f\n",ans.real(),ans.imag());
  }
  return 0;
}