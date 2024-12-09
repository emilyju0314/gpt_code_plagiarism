#include<bits/stdc++.h>
using namespace std;

int main(){
	long long cnt=0,a,b,c;
	cin>>a>>b>>c;
	cnt=(b/c)-(a/c);
	if(a%c==0){
		cnt++;
	}
	cout<<cnt;
	return 0;
}

