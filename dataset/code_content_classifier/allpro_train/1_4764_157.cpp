#include<iostream>
#include<cstdio>
using namespace std;

int main(){
  int a,b;
  cin>>a>>b;
  printf("%d %d %.10f\n",a/b,a%b,(double)a/b);
  return 0;
}