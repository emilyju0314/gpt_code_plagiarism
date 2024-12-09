#include<iostream>
using namespace std;
int A[110];
bool F[100100];
int main()
{
  int N,K;
  cin>>N>>K;
  for(int i=0;i<N;i++)
    cin>>A[i];
  for(int i=1;i<=K;i++)
    for(int j=0;j<N;j++)
      if(i>=A[j])
        F[i]|=(1-F[i-A[j]]);
  if(F[K])
    puts("First");
  else	puts("Second");
  return 0;
}