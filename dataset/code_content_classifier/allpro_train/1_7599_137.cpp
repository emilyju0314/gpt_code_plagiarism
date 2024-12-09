#include <bits/stdc++.h>
using namespace std;
const int maxn=(1<<18)+10;
int n,a[maxn],m;
int f1[maxn],f2[maxn];
int main() {
	//freopen("1.txt","r",stdin);
	scanf("%d",&n);
	m=1<<n;
	for (int i=0;i<m;i++)
		scanf("%d",&a[i]);
	for (int i=1;i<m;i++)
		for (int j=i;j>=0;j=(j-1)&i) {
			if (a[j]>f1[i])
				f2[i]=f1[i],f1[i]=a[j];
			else f2[i]=max(f2[i],a[j]);
			if (j==0) break;
		}
	int s=0;
	for (int i=1;i<m;i++) {
		s=max(s,f1[i]+f2[i]);
		printf("%d\n",s);
	}
	return 0;
}