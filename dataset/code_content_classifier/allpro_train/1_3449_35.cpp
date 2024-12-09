#include<iostream>
#include<algorithm>
using namespace std;
int main(){
	long long n,q[10],v[10],a,b;
	long long x,y,c,d;
	while(true){
	cin>>n;
	if(n==0)break;
	cin>>a>>b;
	q[0]=a,v[0]=b;
	c=q[0],d=v[0];
	while(true){
		if(d>c){
			long long tmp=c;
			c=d;
			d=tmp;
		}
		if(d==c)break;
		c=c%d;
		if(c==0){c=d;break;}
	}
	q[0]/=c,v[0]/=c;
	a/=c,b/=c;
	for(int i=1;i<n;i++){
		cin>>q[i]>>v[i];
		c=q[i],d=v[i];
		while(true){
			if(d>c){
				long long tmp=c;
				c=d;
				d=tmp;
			}
			if(d==c)break;
			c=c%d;
			if(c==0){c=d;break;}
		}
		q[i]/=c,v[i]/=c;
		c=b,d=v[i];
		while(true){
			if(d>c){
				long long tmp=c;
				c=d;
				d=tmp;
			}
			if(d==c)break;
			c=c%d;
			if(c==0){c=d;break;}
		}
		x=c;
		c=a,d=q[i];
		while(true){
			if(d>c){
				long long tmp=c;
				c=d;
				d=tmp;
			}
			if(d==c)break;
			c=c%d;
			if(c==0){c=d;break;}
		}
		y=c;
		a=a*q[i]/y;
		b=x;
		c=a,d=b;
		while(true){
			if(d>c){
				long long tmp=c;
				c=d;
				d=tmp;
			}
			if(d==c)break;
			c=c%d;
			if(c==0){c=d;break;}
		}
		a/=c,b/=c;
	}
	for(int i=0;i<n;i++){
		long long ans=v[i]*a;
		ans/=q[i]*b;
		cout<<ans<<endl;
	}
	}
	return 0;
}