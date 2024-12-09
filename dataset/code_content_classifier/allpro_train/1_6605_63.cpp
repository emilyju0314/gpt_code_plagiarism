#include<iostream>
#include<math.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int arr[n];
		int s1=0;
		int s2=0;
		for(int i=0;i<n;i++)
		{
			cin>>arr[i];
			
			if(arr[i]==1)
			{
				s1=s1+1;
			}
			if(arr[i]==2)
			{
				s2=s2-1;
			}
			else if(arr[i]==3)
			{
				if(s1>=abs(s2))
				{
				   s1=s1+1;
				}
				else
				{
					s1=s1+1;
				}
			}
			
			
		}
		
		cout<<max(s1,s2)<<endl;
	}
	
	
	
	
	return 0;
}