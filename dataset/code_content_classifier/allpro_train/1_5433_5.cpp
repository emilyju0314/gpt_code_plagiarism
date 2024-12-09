#include <bits/stdc++.h>
using namespace std;
const int N=5e6;
const int X[4]={0,1,0,-1},Y[4]={1,0,-1,0};

  int n,m,l,r;
  int q[N],v[N];
#define C getchar()
void in()
{
  cin>>n>>m;
  C;
  for (int i=0;++i<=n;C)
    for (int j=0;++j<=m;)
      if (C=='#')
			  v[q[++r]=i*m+j]=1;
}

  int d[N];
void wor()
{
  while (++l<=r)
    {
      int x=(q[l]-1)/m,y=(q[l]-1)%m+1;
      for (int i=4;~--i;)
        if (x+X[i]&&x+X[i]<=n&&y+Y[i]&&y+Y[i]<=m)
          {
            int p=(x+X[i])*m+(y+Y[i]);
            if (!v[p])
              v[p]=1,
              q[++r]=p,
              d[p]=d[q[l]]+1;
          }
    }
}

void out()
{
  cout<<d[q[r]];
}

int main()
{
  in();
  wor();
  out();
  exit(0);
} 