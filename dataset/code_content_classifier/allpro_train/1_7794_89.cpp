#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int main(void)
{
	int i,len,j,data[7],wk;
	char buf[101];
	for(i=1;i<=6;i++)	scanf("%d",&data[i]);
	scanf("%s",buf);
	len=strlen(buf);
	for(i=0;i<len;i++)	{
		if(buf[i]=='N')	{
			wk=data[1];
			data[1]=data[2];
			data[2]=data[6];
			data[6]=data[5];
			data[5]=wk;
		}
		if(buf[i]=='S')	{
			wk=data[1];
			data[1]=data[5];
			data[5]=data[6];
			data[6]=data[2];
			data[2]=wk;
		}
		if(buf[i]=='E')	{
			wk=data[1];
			data[1]=data[4];
			data[4]=data[6];
			data[6]=data[3];
			data[3]=wk;
		}
		if(buf[i]=='W')	{
			wk=data[1];
			data[1]=data[3];
			data[3]=data[6];
			data[6]=data[4];
			data[4]=wk;
		}
	}
	printf("%d\n",data[1]);
	return 0;
}
