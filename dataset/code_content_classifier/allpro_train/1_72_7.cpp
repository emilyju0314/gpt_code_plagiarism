#include<iostream>
#include<vector>
#include<array>
#include<algorithm>
using namespace std;
int n;
int rd()
{
	int ret=0;
	for(int i=0;i<16;i++)
	{
		int a;cin>>a;
		ret+=a<<i;
	}
	return ret;
}
vector<int>G[9];
int F[9];
int main()
{
	G[0].push_back(0);
	G[0].push_back(1);
	G[0].push_back(2);
	G[0].push_back(3);
	G[0].push_back(6);
	G[1].push_back(0);
	G[1].push_back(1);
	G[1].push_back(2);
	G[1].push_back(4);
	G[1].push_back(7);
	G[2].push_back(0);
	G[2].push_back(1);
	G[2].push_back(2);
	G[2].push_back(5);
	G[2].push_back(8);
	G[3].push_back(0);
	G[3].push_back(3);
	G[3].push_back(4);
	G[3].push_back(5);
	G[3].push_back(6);
	G[4].push_back(1);
	G[4].push_back(3);
	G[4].push_back(4);
	G[4].push_back(5);
	G[4].push_back(7);
	G[5].push_back(2);
	G[5].push_back(3);
	G[5].push_back(4);
	G[5].push_back(5);
	G[5].push_back(8);
	G[6].push_back(0);
	G[6].push_back(3);
	G[6].push_back(6);
	G[6].push_back(7);
	G[6].push_back(8);
	G[7].push_back(1);
	G[7].push_back(4);
	G[7].push_back(6);
	G[7].push_back(7);
	G[7].push_back(8);
	G[8].push_back(2);
	G[8].push_back(5);
	G[8].push_back(6);
	G[8].push_back(7);
	G[8].push_back(8);
	F[0]=1<<0|1<<1|1<<4|1<<5;
	F[1]=1<<1|1<<2|1<<5|1<<6;
	F[2]=1<<2|1<<3|1<<6|1<<7;
	F[3]=1<<4|1<<5|1<<8|1<<9;
	F[4]=1<<5|1<<6|1<<9|1<<10;
	F[5]=1<<6|1<<7|1<<10|1<<11;
	F[6]=1<<8|1<<9|1<<12|1<<13;
	F[7]=1<<9|1<<10|1<<13|1<<14;
	F[8]=1<<10|1<<11|1<<14|1<<15;
	while(cin>>n,n)
	{
		vector<array<int,6> >now;
		int ret=rd();
		if(!(ret&F[4]))
		{
			array<int,6>a;
			for(int i=0;i<5;i++)a[i]=-1;
			a[5]=4;
			now.push_back(a);
		}
		for(int i=1;i<n;i++)
		{
			ret=rd();
			bool ok[9]={};
			for(int j=0;j<9;j++)ok[j]=!(ret&F[j]);
			vector<array<int,6> >tmp;
			for(int j=0;j<now.size();j++)
			{
				array<int,6>a=now[j];
				int out=(1<<16)-1;
				if(a[0]==-1)out=0;
				for(int k=0;k<6;k++)if(a[k]>=0)out&=~F[a[k]];
				for(int k=0;k<5;k++)
				{
					int v=G[a[5]][k];
					if(ok[v]&&!(out&~F[v]))
					{
						array<int,6>b;
						for(int l=0;l<5;l++)b[l]=a[l+1];
						b[5]=v;
						tmp.push_back(b);
					}
				}
			}
			sort(tmp.begin(),tmp.end());
			tmp.erase(unique(tmp.begin(),tmp.end()),tmp.end());
			now=tmp;
		}
		cout<<!now.empty()<<endl;
	}
}

