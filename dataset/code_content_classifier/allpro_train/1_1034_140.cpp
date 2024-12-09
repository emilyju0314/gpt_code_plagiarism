#include<stdio.h>

int main()
{
	int n=1,m=1;
	int obj[1001],max,min,temp=0;
	while(1)
	{
		max=0;
		min=2000000;
		
		scanf("%d",&n);
		scanf("%d",&m);
		
		if(n==0 && m==0) break;
		
		for(int i=0;i<n;i++)
		{
			scanf("%d",&obj[i]);
		}
		for(int i=0;i<n;i++)
		{
			for(int t=i+1;t<n;t++)
			{
				temp=obj[i]+obj[t];
				if(temp>max && temp<=m) max=temp;
				if(temp<min) min=temp;
			}
		}
		if(min>m) printf("NONE\n");
		else printf("%d\n",max);
	}
	
	return 0;
}
