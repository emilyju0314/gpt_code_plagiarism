#include <bits/stdc++.h>
using namespace std;
 
int main(){
	int k;
	cin >> k;
	long long int m[k]; 
	for(int i=0;i<k;i++){
	cin >> m[i];
}
	long long int a,b,c;
	a=2;
	b=2;
	for(int j=k-1;j >= 0;j--){
	c=b%(m[j]);
	if(a-1 < (b-c)){
	a=(((a-1)/(m[j]))+1)*(m[j]);
	b=b-c+(m[j])-1;
}
	if(a > (b-c)){
	a=1;
	b=1;
}
}
	if((a == 1) && (b == 1)){
	cout << -1 << endl;
    }else{
		cout << a << ' ' << b << endl;
    }
}
