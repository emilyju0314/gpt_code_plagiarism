#include<bits/stdc++.h>
using namespace std;

#define i64 long long int
#define ran 303

int n, m;
int h[ran];
i64 f[ran][ran][ran];

void upd(i64 &a, i64 b) {
	if(a<0 || a>b) a = b;
}

int main() {
	scanf("%d%d", &n, &m);
	for(int i=1;i<=n;i++) scanf("%d", &h[i]);
	h[0] = 0;
	
	memset(f, -1, sizeof f);
	f[0][0][0] = 0;
	for(int i=0;i<n;i++)
	for(int j=0;j<=i;j++)
	for(int k=0;k<=m;k++) {
		if(f[i][j][k]<0) continue;
		upd(f[i+1][i+1][k], f[i][j][k] + max(0, h[i+1]-h[j]));
		if(k<m)
			upd(f[i+1][j][k+1], f[i][j][k]);
	}
	
	i64 ans = -1LL;
	for(int j=0;j<=n;j++)
	for(int k=0;k<=m;k++)
		if(f[n][j][k]>=0)
			upd(ans, f[n][j][k]);
	cout<<ans<<endl;
	
	return 0;
}