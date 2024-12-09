#include<cstdio>
#include<algorithm>
using namespace std;

int main(){
	int n;
	int a[3];
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d %d %d",&a[0],&a[1],&a[2]);
	sort(a,a+3);
	if(a[2]*a[2]==a[0]*a[0]+a[1]*a[1]) printf("YES\n");
	else printf("NO\n");
	}
	return 0;
}