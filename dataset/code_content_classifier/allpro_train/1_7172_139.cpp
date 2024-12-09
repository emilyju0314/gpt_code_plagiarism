#include<cstdio>
#include<bitset>
using namespace std;

bitset<50001> pt;

void MakeTable(int n){
  pt.reset();
  pt.set(2);
  
  int i;
  for(i=3;i<=n;i+=2)pt.set(i);
  
  i = 3;
  while(i*i<=n){
    for(int j=3*i;j<=n;j+=i)pt.reset(j);
    while(!pt[++i]);
  }
}

int main(){
  int n,ans;
  MakeTable(50000);

  while(scanf("%d",&n) && n){
    if(n&1)pt[n-2]?printf("1\n"):printf("0\n");
    else{
      ans = 0;
      for(int i=0;i<=n/2;i++)
	if(pt[i] && pt[n-i])ans++;
      printf("%d\n",ans);
    }
  }
}
	