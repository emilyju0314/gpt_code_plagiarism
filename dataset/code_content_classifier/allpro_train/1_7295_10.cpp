#include <iostream>
using namespace std;
const int N=1000010;
int a[N],b[N];
int main() {
	int t;
	scanf("%d",&t);
	while(t--) {
		int n;
		scanf("%d",&n);
		int n1=n;
		for(int i=1; i<=n; i++) {
			scanf("%d",&a[i]);
			b[a[i]]=i;
		}
		int x=b[n];
		while(n1) 
		{
			int y=0;
			for(int i=x; i<=n; i++)
				if(a[i]) {
					printf("%d ",a[i]);
					a[i]=0;
					y++;
				}
			n1-=y;
			x=b[--n];
		}
		puts("");
	}
}
	   	 		 	         		 	     	 	