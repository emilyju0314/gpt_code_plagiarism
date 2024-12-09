#include<cstdio>
#include<queue>
int N,p[200010],st[2][18][100010],log[100010];
int minp(int a,int b){return p[a]<p[b]?a:b;}
int qry(int t,int l,int r){
	int k=log[r-l];
	return minp(st[t][k][l],st[t][k][r-(1<<k)]);
}
struct item{
	int l,r,pl,pr;
	bool operator<(const item&it)const{
		return p[pl]>p[it.pl];
	}
};
item get(int l,int r){
	int pl=qry(l%2,l/2,r/2),pr=qry((l+1)%2,(pl+1)/2,(r+1)/2);
	return(item){l,r,pl,pr};
}
std::priority_queue<item>Q;
int main(){
	scanf("%d",&N);
	for(int i=0;i<N;i++)scanf("%d",p+i),st[i%2][0][i/2]=i;
	N/=2;
	for(int i=2;i<=N;i++)log[i]=log[i/2]+1;
	for(int t=0;t<2;t++)
		for(int k=1;k<=log[N];k++)
			for(int i=0;i+(1<<k)<=N;i++)
				st[t][k][i]=minp(st[t][k-1][i],st[t][k-1][i+(1<<k-1)]);
	Q.push(get(0,N*2));
	while(!Q.empty()){
		item it=Q.top();Q.pop();
		printf("%d %d ",p[it.pl],p[it.pr]);
		if(it.l<it.pl)Q.push(get(it.l,it.pl));
		if(it.pl+1<it.pr)Q.push(get(it.pl+1,it.pr));
		if(it.pr+1<it.r)Q.push(get(it.pr+1,it.r));
	}
}