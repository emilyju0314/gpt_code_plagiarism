#include<cstdio>
#include<cstring>
#include<algorithm>
 
using namespace std;
const int maxn=1020;
 
int n, m, a[maxn]; 
 
int query(int a, int b, int c, int d, int e, int f) {
	printf("? %d %d %d %d %d %d\n", a, b, c, d, e, f);
	fflush(stdout);
	int x; scanf("%d", &x);
	return x;
}
 
int chk(int ty, int r, int k) {
	if(ty==0) {
		if(k==2) return query(r/2, m, 1, 1, r/2+1, 1);
		int mid=k/2*(r/k);
		return query(mid, m, 1, 1, mid+1, 1)&&query(mid, m, 1, 1, mid+r/k+1, 1);
	} else {
		if(k==2) return query(n, r/2, 1, 1, 1, r/2+1);
		int mid=k/2*(r/k);
		return query(n, mid, 1, 1, 1, mid+1)&&query(n, mid, 1, 1, 1, mid+r/k+1);
	}
}
 
int main() {
	scanf("%d%d", &n, &m);
	int ans=0, now=1, k=n;
	for(int i=2; i*i<=k; ++i) {
		if(k%i==0) {
			int ff=1;
			while(k%i==0) {
				k/=i;
				if(ff&&chk(0, n/now, i)) now*=i; else ff=0;
			}
		}
	}
	if(k>1) if(chk(0, n/now, k)) now*=k;
	for(int i=1; i<=now; ++i) if(now%i==0) ++ans;
	int p=0; now=1, k=m;
	for(int i=2; i*i<=k; ++i) {
		if(k%i==0) {
			int ff=1;
			while(k%i==0) {
				k/=i;
				if(ff&&chk(1, m/now, i)) now*=i; else ff=0;
			}
		}
	}
	if(k>1) if(chk(1, m/now, k)) now*=k;
	for(int i=1; i<=now; ++i) if(now%i==0) ++p;
	printf("! %d", ans*p);
	fflush(stdout);
	return 0;
}