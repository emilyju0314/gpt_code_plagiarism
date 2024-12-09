#include <iostream>
#include <algorithm>
#include <numeric>

int n,m,r;
int c[10];
long long d[210][210];
constexpr long long inf=10000000000000;
int main(){
  std::cin>>n>>m>>r;
  
  for(int i=0;i<n;++i)
    std::fill(d[i],d[i]+n,inf);
  for(int i=0;i<n;++i)
    d[i][i]=0;
  
  for(int i=0;i<r;++i){
    std::cin>>c[i];
    --c[i];
  }
  for(int i=0;i<m;++i){
    int x,y;
    long long z;
    std::cin>>x>>y>>z;
    --x,--y;
    d[x][y]=z;
    d[y][x]=z;
  }
  
  for(int i=0;i<n;++i)
    for(int j=0;j<n;++j)
      for(int k=0;k<n;++k)
        d[j][k]=std::min(d[j][k],d[j][i]+d[i][k]);
  
  long long ans=inf;
  int l[10];
  std::iota(l,l+r,0);
  do{
    long long res=0;
    for(int i=0;i<r-1;++i)
      res+=d[c[l[i]]][c[l[i+1]]];
    ans=std::min(ans,res);
  }while(std::next_permutation(l,l+r));
  std::cout<<ans<<std::endl;
  return 0;
}
