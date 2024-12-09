#include<cstdio>
#include<algorithm>
using namespace std;

const int Maxn=500;

int N,A[Maxn+5][Maxn+5];

void Solve(int l,int r,int id) {
	if(l==r)return;
	int mid=(l+r)>>1;
	for(int i=l;i<=mid;i++)
		for(int j=mid+1;j<=r;j++)
			A[i][j]=id;
	Solve(l,mid,id+1),Solve(mid+1,r,id+1);
}

int main() {
	#ifdef LOACL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	scanf("%d",&N);
	Solve(1,N,1);
	for(int i=1;i<N;i++) {
		for(int j=i+1;j<N;j++)
			printf("%d ",A[i][j]);
		printf("%d\n",A[i][N]);
	}
	return 0;
}