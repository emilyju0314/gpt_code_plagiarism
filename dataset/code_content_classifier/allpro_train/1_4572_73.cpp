#include <iostream>
#include <string>
using namespace std;
int main(){
	int n;
	for(cin>>n;n--;){
		string a,b;
		cin>>a>>b;
		int f=0;
		if(a.size()<b.size())swap(a,b);
		while(a.size()>b.size())b="0"+b;
		for(int i=a.size()-1;i>=0;i--){
			a[i]+=(b[i]-'0'+f);
			if(a[i]>'9'){
				f=1;
				a[i]-=10;
			}
			else f=0;
		}
		if(f)a="1"+a;
		cout<<(a.size()>80?"overflow":a)<<endl;
	}
	return 0;
}
