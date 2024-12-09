#include<iostream>
#include<algorithm>
using namespace std;
int N;
string s[500];
int main()
{
	cin>>N;
	for(int i=0;i<N;i++)cin>>s[i];
	int ans=1e9;
	for(int i=0;i<N;i++)
	{
		bool exs=false;
		int A=0,B=0,C=0;
		for(int j=0;j<N;j++)exs|=s[j][i]=='#';
		if(!exs)
		{
			for(int j=0;j<N;j++)if(s[i][j]=='#')
			{
				C=1;
				break;
			}
			if(!C)continue;
		}
		for(int j=0;j<N;j++)
		{
			if(s[i][j]=='#')
			{
				for(int k=0;k<N;k++)if(s[k][j]=='.')
				{
					A++;
					break;
				}
			}
			else B++;
		}
		ans=min(ans,A+B*2+C);
	}
	cout<<(ans<1e9?ans:-1)<<endl;
}