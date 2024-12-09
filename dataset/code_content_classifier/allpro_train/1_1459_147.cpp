#include<iostream>
using namespace std;
long long n,a,b,c,d,maxn,minn,flag=0;
int main()
{
	cin>>n>>a>>b>>c>>d;
	if(a>b){
		long long temp=a;
		a=b;
		b=temp;
	}
	for(int i=0;i<=n-1;i++){
		maxn=i*d-(n-1-i)*c;
		minn=i*c-(n-1-i)*d;
		if(a+maxn>=b&&a+minn<=b){
			flag=1;
		}
	}
	if(flag==1){
		cout<<"YES"<<endl; 
	}
	else{
		cout<<"NO"<<endl;
	}
	return 0;
}