#include<iostream>
#include<algorithm>
#define INF (1e9)
#define N c[n-1]*2
using namespace std;
int main(){
  int n,c[50],k=0;
  while(cin>>n&&n){
    k++;
    for(int i=0;i<n;i++)cin>>c[i];
    cout<<"Case #"<<k<<": ";
    if(c[0]==1){
      int dp[2001]={};
      for(int i=1;i<=N;i++)dp[i]=INF;
      for(int i=0;i<n;i++)
	for(int j=c[i];j<=N;j++)
	  dp[j]=min(dp[j],dp[j-c[i]]+1);
      int f=0;
      for(int i=1;i<=N;i++){
	int a=0,s=i;
	for(int j=n-1;s!=0;j--){
	  a+=s/c[j];
	  s%=c[j];
	}
	if(a!=dp[i]){f=1;break;}
      }
      if(f)cout<<"Cannot use greedy algorithm"<<endl;
      else cout<<"OK"<<endl;
    }
    
    else cout<<"Cannot pay some amount"<<endl;
  }
  return 0;
}