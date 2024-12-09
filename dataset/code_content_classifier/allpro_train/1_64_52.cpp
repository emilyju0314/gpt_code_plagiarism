#include<bits/stdc++.h>
using namespace std;
const int N = 100005;
int X,K,Q,r[N],t[N],x[N],la,lb,a,b,c,t1,t2,add,tmp,diff,f;
int main() {
//	freopen("data.in","r",stdin);
	cin>>X;
	cin>>K;
	for(int i=1;i<=K;i++)
		cin>>r[i];
	cin>>Q;
	for(int i=1;i<=Q;i++)
		cin>>t[i]>>x[i];
	t1=0,t2=1;
	a=0,b=X,f=-1;
	while(t2<=Q) {
		if(t[t2]>r[t1+1]&&t1<K) {
			t1++;
			add=f*(r[t1]-r[t1-1]);
//			b=max(0ll,max(0ll,min(X,X-f*add))-c);
//			a=min(X,min(X,max(0ll,0ll-f*add))-c);
			b+=add,a+=add;
			b=max(0,min(X,b)),a=max(0,min(X,a));
			c+=add;
			f*=-1;
		}
		else {
			diff=t[t2]-r[t1];
			tmp=max(a,min(b,x[t2]+c));
			tmp+=diff*f;
			tmp=max(0,min(X,tmp));
			cout<<tmp<<endl;
			t2++;
		}
	}
	return 0;
}