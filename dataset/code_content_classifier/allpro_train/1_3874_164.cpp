#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
#define INF 1000000007
using namespace std;

int main(){
  long n;
  cin >> n;
  long ans = 1;
  long tmp = n;
  for(long i=2;i<=sqrt(n);i++){
    tmp = n;
    while(tmp%i==0)tmp /= i;
    if(tmp%i==1){
      ans++;
    }
  }
  for(long j=2;j<=sqrt(n);j++){
    if((n-1)%j==0 && (n-1)/j>sqrt(n))ans++;
  }
  cout << ans+(n>2) << endl;
  return 0;
}