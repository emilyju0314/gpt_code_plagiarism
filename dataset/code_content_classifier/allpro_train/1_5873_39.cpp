#include<bits/stdc++.h>
#define r(i,n) for(int i=0;i<n;i++)
using namespace std;
int main(){
  int n,ans=1e9;
  cin>>n;
  int a[n],b[n];
  r(i,n)cin>>a[i];
  r(i,n)b[i]=a[i];
  r(j,4){
    int s1=0;
    r(i,n)a[i]=b[i];
    a[0]-=j;
    for(int i=0;i<n-1;i++){
      if(a[i]<=0)continue;
      s1+=a[i]*2;
      a[i+1]-=a[i];
    }
    if(a[n-1]<0)a[n-1]=0;
    ans=min(ans,s1+a[n-1]+j);
  }
  cout<<ans<<endl;
}