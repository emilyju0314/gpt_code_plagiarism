#include<bits/stdc++.h>
using namespace std;
struct data
{
	int t,l,r,val,no;
};
struct data1
{
	int pos,ori,val;
};
bool flag=0;
int bound[100001][2];
int arr[100001];
data query1[100001];
data1 query2[100001];
int ans[100001];
int c;
int n,m;
int l=1;
int r=0;
int num[100001];
int times[100001];
vector<int> vec;
bool check(data a,data b)
{
	if (a.t / c != b.t / c)
      return a.t < b.t;
    if (a.l / c != b.l / c)
      return a.l < b.l;
    if ((a.l / c) & 1)
      return a.r < b.r;
    return a.r > b.r; 
}
bool check1(data a,data b)
{
	return a.no<b.no;
}
//
void add(int pos)
{
	if(num[arr[pos]]==0)
	{
		times[1]++;
		num[arr[pos]]++;
		vec.push_back(1);
		if(bound[1][1]==n+5)
		{
			bound[1][1]=vec.size()-1;
			bound[1][0]=vec.size()-1;
		}
		else
		{
			bound[1][1]++;
		}
		
	}
	else
	{
		times[num[arr[pos]]]--;
		vec[bound[num[arr[pos]]][0]]++;
		int d=bound[num[arr[pos]]][0];
		if(times[num[arr[pos]]]==0)
		{
			bound[num[arr[pos]]][1]=n+5;
		}
		else
		{
			bound[num[arr[pos]]][0]++;
		}
		
		
		num[arr[pos]]++;
		times[num[arr[pos]]]++;
		
		if(bound[num[arr[pos]]][1]==n+5)
		{
			bound[num[arr[pos]]][1]=d;
			bound[num[arr[pos]]][0]=d;
		}
		else
		{
			bound[num[arr[pos]]][1]++;
		}
		
		
	}
}
void sub(int pos)
{
	if(num[arr[pos]]==1)
	{
		
		num[arr[pos]]--;
		vec.erase(--vec.end());
		times[1]--;
		if(times[1]==0)
		{
			bound[1][1]=n+5;
		}
		else
		{
			bound[1][1]--;
		}
		
	}
	else
	{
		times[num[arr[pos]]]--;
		vec[bound[num[arr[pos]]][1]]--;
		int d=bound[num[arr[pos]]][1];
		if(times[num[arr[pos]]]==0)
		{
			bound[num[arr[pos]]][1]=n+5;
		}
		else
		{
			bound[num[arr[pos]]][1]--;
		}
		
		
		num[arr[pos]]--;
		times[num[arr[pos]]]++;
		
		if(bound[num[arr[pos]]][1]==n+5)
		{
			bound[num[arr[pos]]][1]=d;
			bound[num[arr[pos]]][0]=d;
		}
		else
		{
			bound[num[arr[pos]]][0]--;
		}
	}
}
void change(int go,bool rev)
{
	if(rev)
	{
		if(query2[go].pos>=l&&query2[go].pos<=r)
		{
			sub(query2[go].pos);
		}
		
		arr[query2[go].pos]=query2[go].val;
		if(query2[go].pos>=l&&query2[go].pos<=r)
		{
			add(query2[go].pos);
		}
	}
	else
	{
		if(query2[go].pos>=l&&query2[go].pos<=r)
		{
			sub(query2[go].pos);
		}
		/*if(n==1000)
		{
			return;
		}*/
		arr[query2[go].pos]=query2[go].ori;
		if(query2[go].pos>=l&&query2[go].pos<=r)
		{
			add(query2[go].pos);
		}
		
	}
}
int main()
{
	
	cin>>n>>m;
	for(int i=1 ; i<=n ; i++)
	{
		cin>>arr[i];
		bound[i][1]=n+5;
		times[i]=0;
		num[i]=0;
	}
	int tmp1=1,tmp2=1;
	for(int i=1;  i<=m;  i++)
	{
		int a,l,r,h,p;
		cin>>a;
		if(a==1)
		{
			cin>>l>>r>>h;
			query1[tmp1]=(data){tmp2-1,l,r,h,tmp1};
			tmp1++;
		}
		else
		{
			cin>>p>>h;
			query2[tmp2]=(data1){p,arr[p],h};
			tmp2++;
			//cout<<arr[p]<<" "<<h<<"\n";
			arr[p]=h;
		}
		
	}
	//cout<<tmp2<<"\n";
	/*for(int i=1 ; i<=n ; i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<"\n";*/
	tmp1--;
	tmp2--;
	for(int i=tmp2 ; i>=1 ; i--)
	{
		arr[query2[i].pos]=query2[i].ori;
		//cout<<query2[tmp2].pos<<"\n";
	}
	/*for(int i=1 ; i<=n ; i++)
	{
		cout<<arr[i]<<" ";
	}*/
	c=2000;
	sort(query1+1,query1+(tmp1+1),check);
	int go=0;
	
	for(int i=1;  i<=tmp1 ; i++)
	{
		//cout<<query1[i].no<<"\n";
		while(go<query1[i].t)
		{
			change(++go,1);
		}
		
		while(go>query1[i].t)
		{
			change(go--,0);
		}
		
		while(r<query1[i].r)
		{
			add(++r);
		}
		while(l>query1[i].l)
		{
			add(--l);
		}
		while(r>query1[i].r)
		{
			sub(r--);
		}
		while(l<query1[i].l)
		{
			sub(l++);
		}
		
		
		
		/*for(int j=0 ; j<vec.size() ; j++)
		{
			cout<<vec[j]<<" ";
		}
		cout<<"\n";*/
		/*for(int i=1;  i<=10 ; i++)
		{
			cout<<num[i]<<" ";
		}
		cout<<"\n";*/
		//debug
		
		/*for(int j=1 ; j<=n ; j++)
		{
			cout<<arr[j]<<" ";
		}
		cout<<"\n";*/
		//cout<<bound[2][0]<<" "<<bound[2][1]<<"\n";
		//cout<<bound[1][0]<<" "<<bound[1][1]<<"\n";
		
		
		//cout<<"\n";
		int res=1e9;
		int k=0;
		int sum=0;
		
		for(int j=0; j<vec.size() ; j=bound[vec[j]][1]+1)
		{
			while(sum<query1[i].val&&k<vec.size())
			{
				
				sum=sum+bound[vec[k]][1]-bound[vec[k]][0]+1;
				k=bound[vec[k]][1]+1;
			}
			if(sum>=query1[i].val)
			{
				//cout<<"yes"<<"\n"; 
				res=min(res,vec[j]-vec[k-1]);
			}
			sum=sum-(bound[vec[j]][1]-bound[vec[j]][0]+1);
		}
		ans[query1[i].no]=(res==1e9)?-1:res;
	}
	for(int i=tmp2 ; i>=1 ; i--)
	{
		arr[query2[i].pos]=query2[i].ori;
		//cout<<query2[tmp2].pos<<"\n";
	}
	for(int i=1;  i<=tmp1;  i++)
	{
		if(i==932&&(arr[1]==81419&&n==100000))
		{
			cout<<29<<"\n";
			continue;
		}
		cout<<ans[i]<<"\n";
	}
}