#include <bits/stdc++.h>
using namespace std;

const int maxn=1e5+4;
int p[maxn];
int ans[maxn];
int ld[maxn];
int id[maxn];
int n,m,k;

int fleader(int x){
	return (x==p[x]? x:p[x]=fleader(p[x]));	
}

void unite(int x,int y){
	int px=fleader(x);
	int py=fleader(y);
	p[px]=py;
	return;	
}

bool cmp(int i,int j){
	return ld[i]<ld[j];	
}

int main(){
	vector<int> q;
	cin >> n >> m >> k;
	for (int i=1;i<=n;i++){
		p[i]=i;	
	}
	for (int i=1,x,y;i<=m;i++){
		cin >> x >> y;
		unite(x,y);
		ans[x]--;
		ans[y]--;
	}	
	for (int i=1,x,y;i<=k;i++){
		cin >> x >> y;
		if (fleader(x)!=fleader(y))continue;
		ans[x]--;
		ans[y]--;	
	}
	for (int i=1;i<=n;i++){
		id[i]=i;
		ld[i]=fleader(i);
	}
	sort(id+1,id+n+1,cmp);
	int tot=1,len=1;
	for (int i=2;i<=n+1;i++){
		if (i!=n+1 && ld[id[i]]==ld[id[i-1]]){len++;continue;}
		for (int j=tot;j<=i-1;j++){
			ans[id[j]]+=(len-1);	
		}
		len=1;
		tot=i;
	}
	cout << endl;
	for (int i=1;i<=n;i++){
		cout << ans[i] << ' ';
	}
	return 0;
}	