#include<bits/stdc++.h>
int n,x,y,i,j,a[2001];
int main(){
  std::cin>>n>>x>>y;
  for(;++i<=n;)
    for(j=i;++j<=n;)
      a[std::min(j-i,abs(x-i)+1+abs(y-j))]++;
       for(i=0;++i<n;
          )
         printf("%d\n",a[i]);
}
