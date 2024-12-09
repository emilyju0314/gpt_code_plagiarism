#include <vector> 
#include <list> 
#include <map> 
#include <set> 
#include <deque> 
#include <queue> 
#include <stack> 
#include <bitset> 
#include <algorithm> 
#include <functional> 
#include <numeric> 
#include <utility> 
#include <sstream> 
#include <iostream> 
#include <iomanip> 
#include <cstdio> 
#include <cmath> 
#include <cstdlib> 
#include <cctype> 
#include <string> 
#include <cstring> 
#include <ctime> 

using namespace std;

#define _int64 long long

int a[110000];
_int64 d[110000][32];

int main()
{
  _int64 ans;
  int i,j,n,pre,b1,tmp1,tmp2,tmp3,tmp4,mi,c0,c1,tmp;
  scanf("%d",&n);
  for (i=0;i<n;i++)
    scanf("%d",&a[i]);
  memset(d,-1,sizeof(d));
  d[0][0]=0;
  for (i=0;i<n;i++)
  {
    tmp=a[i];
    c0=0;c1=0;
    while (tmp!=1)
    {
      c0++;
      if (tmp%2==1) c1=1;
      tmp=(tmp+1)/2;
    }
    if ((c0>0)&&(c1==1))
    {
      c0--;
    }
    //cout<<"c:"<<c0<<" "<<c1<<endl;
    for (j=0;j<32;j++)
      if (d[i][j]!=-1)
      {
        tmp=d[i][j];
        tmp1=j;
        tmp2=c0;
        tmp3=c1;
        tmp4=0;
        if (tmp2>=tmp1)
        {
          tmp4=c0+c1;
        }
        else if (tmp2+tmp3>=tmp1)
        {
          tmp+=(tmp1-tmp2);
          tmp4=tmp2+tmp3-(tmp1-tmp2);
        }
        else
        {
          tmp4=tmp2;
          tmp+=tmp1-tmp2;
        }
        if ((d[i+1][tmp4]==-1)||(tmp<d[i+1][tmp4]))
          d[i+1][tmp4]=tmp;
        //cout<<"4: "<<tmp4<<" "<<tmp<<endl;
      }
  }
  ans=2000000000;
  for (i=0;i<32;i++)
    if (d[n][i]!=-1)
    {
      if (d[n][i]+i<ans) ans=d[n][i]+i;
    }
  printf("%lld\n",ans);
  return 0;
}