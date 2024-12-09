#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;

int main(){
  double a, b, x;
  cin >> a >> b >> x;
  x /= a;
  double theta;
  if(x < a*b/2){
    theta = atan(b*b/2/x);
  }else{
    theta = asin(1) - atan(a*a/2/(a*b-x));
  }
  theta *= 180.0/acos(-1);
  printf("%.12f\n",theta);
}
