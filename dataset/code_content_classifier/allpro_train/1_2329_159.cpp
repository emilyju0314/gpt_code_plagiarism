#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
int coun[105][105][105];
vector<int>x,y,z;
int rx[52][2], ry[52][2], rz[52][2];
int a[52],b[52],c[52],d[52],e[52],f[52];
int n,m;

int compress1(){
	for(int i = 0;i < n;i++){
		x.push_back(a[0]);
		x.push_back(d[0]);
	}
	sort(x.begin(), x.end());
	x.erase(unique(x.begin(), x.end()), x.end());
	for(int i = 0;i < n;i++){
		rx[i][0] = find(x.begin(),x.end(),a[i])-x.begin();
		rx[i][1] = find(x.begin(),x.end(),d[i])-x.begin();
	}
	return 0;
}

int main()
{
  scanf("%d %d",&n,&m);
  for(int i=0;i<n;i++)
    {
      scanf("%d %d %d %d %d %d",&a[i],&b[i],&c[i],&d[i],&e[i],&f[i]);
       x.push_back(a[i]);
       x.push_back(d[i]);
       y.push_back(b[i]);
       y.push_back(e[i]);
       z.push_back(c[i]);
       z.push_back(f[i]);
    }
  sort(x.begin(),x.end());
  sort(y.begin(),y.end());
  sort(z.begin(),z.end());
  x.erase(unique(x.begin(),x.end()),x.end());
  y.erase(unique(y.begin(),y.end()),y.end());
  z.erase(unique(z.begin(),z.end()),z.end());
  for(int i=0;i<n;i++)
    {
      int r1=find(x.begin(),x.end(),a[i])-x.begin();
      int r2=find(x.begin(),x.end(),d[i])-x.begin();
      int r3=find(y.begin(),y.end(),b[i])-y.begin();
      int r4=find(y.begin(),y.end(),e[i])-y.begin();
      int r5=find(z.begin(),z.end(),c[i])-z.begin();
      int r6=find(z.begin(),z.end(),f[i])-z.begin();
      for(int i=r1;i<r2;i++)
    {
      for(int j=r3;j<r4;j++)
        {
          for(int k=r5;k<r6;k++)
        {
          coun[i][j][k]++;
        }
        }
    }
    }
  long long ans=0;
  for(int i=0;i<=100;i++)
    {
      for(int j=0;j<=100;j++)
    {
      for(int k=0;k<=100;k++)
        {
          if(coun[i][j][k]>=m)
        {
          long long s1=(x[i+1]-x[i]),s2=(y[j+1]-y[j]),s3=(z[k+1]-z[k]);
          ans+=s1*s2*s3;
        }
        }
    }
    }
  printf("%lld\n",ans);
  return 0;
}