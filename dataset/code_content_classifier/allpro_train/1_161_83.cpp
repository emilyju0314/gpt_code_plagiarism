//19
#include<iostream>
#include<algorithm>
#include<cstdlib>

using namespace std;

int main(){
  int n;
  cin>>n;
  int a[20];
  for(int i=0;i<n;i++){
    cin>>a[i];
  }
  static double dp[2][200000];
  fill(dp[0],dp[2],1<<30);
  dp[0][1]=0;
  for(int i=1;i<=n;i++){
    fill(dp[i&1],dp[(i&1)+1],1<<30);
    for(int j=1;j<200000;j++){
      for(int k=j;k<200000;k+=j){
	dp[i&1][k]=min(dp[i&1][k],max(dp[i-1&1][j],abs(k-a[i-1])*1./a[i-1]));
      }
    }
  }
  cout.precision(8);
  cout<<fixed<<*min_element(dp[n&1],dp[(n&1)+1])<<endl;
  return 0;
}