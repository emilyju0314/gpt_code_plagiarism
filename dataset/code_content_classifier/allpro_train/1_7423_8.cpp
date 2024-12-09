#include <bits/stdc++.h>
using namespace std;
int main()
{
  int n,k;
  cin >> n >> k;
  double ans=0;
  for(int i=1;i<=n;i++){
    double p = 1.0/n;
    int j=i;
    while(j<k){
      j *=2;
      p /=2;
    }
    ans +=p;
  }
  cout << fixed << setprecision(10) << ans << endl;
}
