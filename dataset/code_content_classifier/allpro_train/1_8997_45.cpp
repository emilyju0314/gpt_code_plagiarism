#include<cstdio>
#include<cstring>
using namespace std;
int main(void)
{
	char mo[10][6]={"",".,!? ","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
	char buf[1025];
	int le[10]={0,5,3,3,3,3,3,4,3,4};
	int i,j,wk,x,px,py,n,len;
	scanf("%d",&n);
	for(i=0;i<n;i++)	{
		scanf("%s",buf);
		len=strlen(buf);
		py=0;	px=-1;
		for(j=0;j<len;j++)	{
			x=buf[j]-'0';
			if(x==0)	{
				if(py!=0)	{
					printf("%c",mo[py][px]);
					py=0;	px=-1;
				}
			}
			else {
				py=x;
				px++;
				px=px%le[py];
			}
//			printf("py=%d px=%d\n",py,px);
		}
		printf("\n");
	}
		
	return 0;
}
