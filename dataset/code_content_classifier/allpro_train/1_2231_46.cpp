#include <bits/stdc++.h>
using namespace std;
int64_t GCD(int64_t a,int64_t b){if(b==0)return a;else return GCD(b,a%b);}
int64_t LCM(int64_t a,int64_t b){return a*b/GCD(a,b);}
int main()
{
  int A,N,M;
  int64_t x=1;
  cin>>N>>M;
  while(cin>>A){x=LCM(x,(A+1)/2);if(x>M||fmod(2*x/A,2)==0)return cout<<0<<endl,0;}
  return cout<<(M/x+1)/2<<endl,0;
}