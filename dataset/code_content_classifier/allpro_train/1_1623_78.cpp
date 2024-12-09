#include<bits/stdc++.h>
using namespace std;
int main()
{
  long long A,B;
  cin>>A>>B;
  A%=B;
  cout<<min(A,B-A)<<endl;
  return 0;
}