#include<bits/stdc++.h>
using namespace std;
int mx;
struct node
{
	int v,tag;
}t[1000001*4];
void pushdown(int node)
{
	t[node*2].v+=t[node].tag;
	t[node*2+1].v+=t[node].tag;
	t[node*2].tag+=t[node].tag;
	t[node*2+1].tag+=t[node].tag;
	t[node].tag=0;
}
void update(int node,int st,int ed,int l,int r,int ind)
{
	if(st>r||ed<l) return;
	if(st>=l&&ed<=r)
	{
		t[node].v+=ind;
		t[node].tag+=ind;
		return;
	}
	pushdown(node);
	int mid=(st+ed)/2;
	update(node*2,st,mid,l,r,ind);
	update(node*2+1,mid+1,ed,l,r,ind);
	t[node].v=max(t[node*2].v,t[node*2+1].v);
}
int query(int node,int st,int ed,int l,int r)
{
	if(st>r||ed<l) return 0;
	if(st>=l&&ed<=r) return t[node].v;
	pushdown(node);
	int mid=(st+ed)/2;
	return max(query(node*2,st,mid,l,r),
					  query(node*2+1,mid+1,ed,l,r));
}
int a[1000001];
vector<int> v[1000001];
int main()
{
	int n;
	scanf("%d%d",&n,&mx);
	for(int i=1;i<=n;i++)
	{
		int l,r;
		scanf("%d%d",&l,&r);
		v[l].push_back(r);
	}
	for(int i=0;i<=mx+1;i++)
		update(1,0,mx+1,i,i,i);
	int ans=0;
	for(int i=0;i<=mx;i++)
	{
		for(int j=0;j<v[i].size();j++)
			update(1,0,mx+1,1,v[i][j],1);
		ans=max(ans,query(1,0,mx+1,i+1,mx+1)-i-mx-1);
	}
	printf("%d",max(ans,n-mx));
    return 0;
}