/*Lucky_Glass*/
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
using namespace std;
typedef long long ll;
const int MAXN=(int)1e9;
map<int,map<int,int> > Pic;
int r,c,n;
ll tot[10];
int main()
{
	scanf("%d%d%d",&r,&c,&n);
	tot[0]=(r-2ll)*(c-2ll);
	for(int i=0;i<n;i++)
	{
		int x,y;scanf("%d%d",&x,&y);
		for(int p=-1;p<=1;p++)
			for(int q=-1;q<=1;q++)
			{
				int X=x+p,Y=y+q;
				if(X<=1 || Y<=1 || X>r-1 || Y>c-1) continue;
				tot[Pic[X][Y]++]--;
				tot[Pic[X][Y]]++;
			}
	}
	for(int i=0;i<10;i++)
		printf("%lld\n",tot[i]);
	return 0;
}
