int maxprofit(int a[], int n,int k)
{
	if(k>=n/2)
	{
		int maxp=0,i;
		for(i=0;i<n;i++)
		{
			if(a[i]>a[i-1])
			maxp+=a[i]-a[i-1];
		}
		return maxp;
	}
}