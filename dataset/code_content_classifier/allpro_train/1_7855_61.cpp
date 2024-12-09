#include<iostream>
#include<algorithm>
using namespace std;
int N_MAX=200001;
int main()
{
  long long n,k,t,i,res;
  long long a[N_MAX],b[N_MAX],c[N_MAX];
  cin >> n >> k;
  for(i=1;i<=n;i++)
    cin >> a[i];
  b[0]=1;
  fill(c+1,c+n+1,-1);
  c[1]=0;
  for(i=1;i<=k;i++){
    b[i]=a[b[i-1]];
    if(c[b[i]]==(-1)){
      c[b[i]]=i;
    }else{
      t=i-c[b[i]];
      k=(k-i)%t+c[b[i]];
      break;
    }
  }
  cout << b[k] << endl;
  return 0;
}