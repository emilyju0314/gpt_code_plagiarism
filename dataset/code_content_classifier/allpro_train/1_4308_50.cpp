#include <iostream>

using namespace std;

int main()
{
  long N;
  cin >> N;

  long long A[200000];


   long i;

   for (i=0;i<N;i++)
      cin >> A[i];

  long long DP[200000];
  long long SUM_A[200000];
  SUM_A[0] = A[0]; // on somme les impairs
  for (i=2;i<N;i+=2)
    SUM_A[i] = SUM_A[i-2] + A[i];


  DP[0] = 0;
  DP[1] = max(A[0],A[1]);

  for (i=3;i<=N;i++) {
    if (i % 2) { // si c'est 7, alors A_7 + DP(5) ou DP(6)
      DP[i-1] = max(DP[i-2],A[i-1]+DP[i-3]);
    }
    else { // si c'est 8
      DP[i-1] = max(SUM_A[i-2],DP[i-3]+A[i-1]);
    }
  }


   cout << DP[N-1] << endl;
  return 0;
}
