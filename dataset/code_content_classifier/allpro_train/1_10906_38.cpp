#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)
#define all(c) c.begin(),c.end()
#define pb push_back
#define fs first
#define sc second
#define show(x) cout << #x << " = " << x << endl
#define chmin(x,y) x=min(x,y)
#define chmax(x,y) x=max(x,y)
using namespace std;
typedef double D;
typedef complex<D> P;
D pi=acos(-1);
P normize(P x){
	return x/abs(x);
}
int main(){
	while(true){
		int N;
		double R;
		cin>>N>>R;
		if(N==0) break;
		P r=P(R,0),l=P(-R,0);
		rep(i,N){
			D a,b,c;
			cin>>a>>b>>c;
			if(a==b){
				D len=a*c*pi/180;
				P x=normize((r-l)*P(0,1));
				r+=len*x,l+=len*x;
			}else{
				P x=(-b*l+a*r)/(a-b);
				D th;
				if(a!=0) th=abs(a)*c*pi/180/abs(l-x);
				else th=abs(b)*c*pi/180/abs(r-x);
				if(a>b) th=-th;
				l=(l-x)*polar(1.0,th)+x,r=(r-x)*polar(1.0,th)+x;
			}
		}
		P m=(l+r)/2.0;
		printf("%.5f\n%.5f\n",m.real(),m.imag());
	}
}