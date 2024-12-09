#include <cstdio>
typedef long long LL;
const int mo=1000000007;
bool a[1005][1005];
char s[1005];
struct M{
	LL a0,a1,a2,a3;
};
M operator *(M A,M B){
	M C;
	C.a0=(A.a0*B.a0+A.a1*B.a2)%mo;
	C.a1=(A.a0*B.a1+A.a1*B.a3)%mo;
	C.a2=(A.a2*B.a0+A.a3*B.a2)%mo;
	C.a3=(A.a2*B.a1+A.a3*B.a3)%mo;
	return C;
}
M operator ^(M A,int B){
	M C=(M){1,0,0,1};
	for (;B;B>>=1,A=A*A)
		if (B&1) C=C*A;
	return C;
}
int ksm(LL x,int y){
	LL i=1;
	for (;y;y>>=1,(x*=x)%=mo)
		if (y&1) (i*=x)%=mo;
	return i;
}
int main(){
	int h,w,x1=0,x2=0,y1=0,y2=0,n=0,ans;
	LL k;
	scanf("%d%d%lld\n",&h,&w,&k);k%=mo-1;
	for (int i=1;i<=h;i++){
		scanf("%s",s+1);
		for (int j=1;j<=w;j++) n+=a[i][j]=s[j]=='#';
	}
	for (int i=1;i<=h;i++){
		x1+=a[i][1]&a[i][w];
		for (int j=1;j<w;j++) x2+=a[i][j]&a[i][j+1];
	}
	for (int j=1;j<=w;j++){
		y1+=a[1][j]&a[h][j];
		for (int i=1;i<h;i++) y2+=a[i][j]&a[i+1][j];
	}
	if (!k || (x1 && y1)) ans=1;
	else if (!x1 && !y1) ans=ksm(n,k-1);
	else{
		if (y1) x1=y1,x2=y2;
		M A=(M){n,0,-x2,x1};
		A=A^(k-1);
		ans=(A.a0+A.a2)%mo;
	}
	printf("%d\n",(ans+mo)%mo);
}