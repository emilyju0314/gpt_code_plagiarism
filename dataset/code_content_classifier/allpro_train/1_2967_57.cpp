#include<bits/stdc++.h>
#define For(i,a,b) for(int i=(a),i##END=(b);i<=i##END;i++)
#define Rof(i,b,a) for(int i=(b),i##END=(a);i>=i##END;i--)
using namespace std;
inline int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
    return x*f;
}
const int N=2e5+9;
int res[N];
struct node{
	int val,id;
	bool operator < (const node &x) const {
		return val<x.val;
	}
}a[N];
inline int min(int a,int b){return a<b?a:b;}
inline int max(int a,int b){return a>b?a:b; }
const int inf=1e9;
struct SegmentTree{
	#define ls t[k].lc
	#define rs t[k].rc
	int idx;
	SegmentTree(){idx=0;}
	struct point{
		int lc,rc,mx,mn,tag;
		point(){lc=rc=tag=mx=mn=0;}
	}t[N<<2];
	void f(int k,int tag){
		t[k].mn+=tag,t[k].mx+=tag,t[k].tag+=tag;
		return;
	}
	void down(int k){
		f(ls,t[k].tag),f(rs,t[k].tag);
		t[k].tag=0;
	}
	void up(int k){
		t[k].mn=min(t[ls].mn,t[rs].mn);
		t[k].mx=max(t[ls].mx,t[rs].mx);
	}
	void build(int &k,int l,int r){
		if(!k)k=++idx;
		if(l==r)return;
		int m=l+r>>1;
		build(ls,l,m),build(rs,m+1,r);
		return;
	}
	int gmn(int k,int l,int r,int x,int y){
		if(x<=l&&r<=y)return t[k].mn;
		int m=l+r>>1,res=inf;down(k);
		if(x<=m)res=min(res,gmn(ls,l,m,x,y));
		if(y>m)res=min(res,gmn(rs,m+1,r,x,y));
		up(k);
		return res;	
	}
	int gmx(int k,int l,int r,int x,int y){
		if(x<=l&&r<=y)return t[k].mx;
		int m=l+r>>1,res=-inf;down(k);
		if(x<=m)res=max(res,gmx(ls,l,m,x,y));
		if(y>m)res=max(res,gmx(rs,m+1,r,x,y));
		up(k);
		return res;	
	}
	void mdf(int k,int l,int r,int x,int y,int val){
		if(x<=l&&r<=y)return t[k].mn+=val,t[k].mx+=val,t[k].tag+=val,void();
		int m=l+r>>1;down(k);
		if(x<=m)mdf(ls,l,m,x,y,val);
		if(y>m)mdf(rs,m+1,r,x,y,val);
		up(k);
		return;
	}
}T1,T2;
#define ii a[k].id
signed main(){
	int n=read();int ttt=114514;
	T1.build(ttt=0,1,n),T2.build(ttt=0,1,n);
	For(i,1,n)a[i].val=read(),a[i].id=i;
	sort(a+1,a+1+n);
	For(i,1,n)T1.mdf(1,1,n,i,n,-1),T2.mdf(1,1,n,1,i,-1);
	For(i,1,n){
		int j=i;while(a[j+1].val==a[i].val)j++;
		For(k,i,j){
			int x=a[k].val,ans=0;
			ans=max(abs(T1.gmn(1,1,n,ii,n)+T2.gmn(1,1,n,1,ii)-T1.gmn(1,1,n,ii,ii)-T2.gmn(1,1,n,ii,ii))+1,
					abs(T1.gmx(1,1,n,ii,n)+T2.gmx(1,1,n,1,ii)-T1.gmx(1,1,n,ii,ii)-T2.gmx(1,1,n,ii,ii)));
			res[ii]=max(res[ii],ans);
		}
		For(k,i,j)T1.mdf(1,1,n,ii,n,2),T2.mdf(1,1,n,1,ii,2);
		For(k,i,j){
			int x=a[k].val,ans=0;
			ans=max(abs(T1.gmn(1,1,n,ii,n)+T2.gmn(1,1,n,1,ii)-T1.gmn(1,1,n,ii,ii)-T2.gmn(1,1,n,ii,ii))+1,
					abs(T1.gmx(1,1,n,ii,n)+T2.gmx(1,1,n,1,ii)-T1.gmx(1,1,n,ii,ii)-T2.gmx(1,1,n,ii,ii)));
			res[ii]=max(res[ii],ans);
		}
		i=j;
	}
	For(i,1,n)printf("%d ",res[i]>>1);
	return 0;
}