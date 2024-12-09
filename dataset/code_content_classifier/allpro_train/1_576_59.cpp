#include <iostream>
using namespace std;

const int N=1e5+10;

int n,q,x,y;
int a[N];
int b[N];
long long sum;

int main(){
	scanf("%d", &n);
	
	for(int i=0;i<n;i++) scanf("%d",&a[i]), b[a[i]]++, sum+=a[i];
	
	scanf("%d", &q);
	while(q--){
		scanf("%d%d",&x,&y);
		sum+=(y-x)*b[x];
		b[y]+=b[x],b[x]=0;
		printf("%ld\n",sum);
	}
	return 0;
}
