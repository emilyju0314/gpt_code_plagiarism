#define _GLIBCXX_DEBUG
#include<bits/stdc++.h>
using namespace std;

int main(){
  int a, b, C;
  double pi, c, S, L, h;
  cin >> a >> b >> C;
  pi=acos(-1);
  S=a*b*sin(C*pi/180)/2;
  c=sqrt(pow(a,2)+pow(b,2)-2*a*b*cos(C*pi/180));
  L=a+b+c;
  h=2*S/a;
  printf("%.5f\n%.5f\n%.5f\n",S,L,h);
  return 0;
}
