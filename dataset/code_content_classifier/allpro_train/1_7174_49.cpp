#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,i,j,k;
  cin>>n;
  double a[n],ans=0,x,y;
  for(i=0;i<n;i++) cin>>a[i];
  sort(a,a+n);
  for(i=0;i<n;i++){
    for(j=i+1;j<n;j++){
      k=n-1;
      while(k==i||k==j) k--;
      x=a[k];k--;
      while(k==i||k==j) k--;
      y=a[k];
      ans=max(ans,(x+y)/(a[j]-a[i]));
    }
  }
  printf("%6lf\n",ans);
  return 0;
}