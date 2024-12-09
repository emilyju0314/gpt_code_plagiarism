#include<bits/stdc++.h>
#define reg register
typedef long long ll;
using namespace std;
typedef pair<int,int>pii;
#define fi first
#define se second
const int MN=1e6+5;
int n,lt[MN],rt[MN],a[MN],b[MN];
char S[MN];
pii A[MN],B[MN];
int main(){
	scanf("%d",&n);
	for(reg int i=1;i<=n;i++){
		scanf("%s",S+rt[i-1]+1);
		lt[i]=rt[i-1]+1;rt[i]=strlen(S+lt[i])+lt[i]-1;
	}
	reg int tot1=0,tot2=0;
	for(reg int i=1;i<=n;i++){
		reg int tot=0;
		for(reg int j=lt[i];j<=rt[i];j++){
			tot+=(S[j]=='('?1:-1);
			a[i]=min(a[i],tot);
		}
		a[i]=-a[i];b[i]=tot+a[i];
		if(a[i]<=b[i])A[++tot1]=make_pair(a[i],b[i]);
		else B[++tot2]=make_pair(a[i],b[i]);
	}
	sort(A+1,A+1+tot1,[](pii a,pii b){
		return a.fi<b.fi;
	});
	reg int res=0;
	for(reg int i=1;i<=tot1;i++){
		if(res<A[i].fi)return 0*puts("No");
		res+=A[i].se-A[i].fi;
	}
	sort(B+1,B+1+tot2,[](pii a,pii b){
		return a.se>b.se;
	});
	for(reg int i=1;i<=tot2;i++){
		if(res<B[i].fi)return 0*puts("No");
		res+=B[i].se-B[i].fi;
	}
	if(res)puts("No");
	else puts("Yes");
	return 0;
}