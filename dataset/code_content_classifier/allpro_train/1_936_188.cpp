#include <iostream>
using namespace std;

bool ary[8];
int main(){
	int N,sum=0;
	cin>>N;
	int tmp;
	for(int i=1;i<=N;i++){
		cin>>tmp;
		if(tmp<3200)ary[(tmp)/400]|=true;
		else sum++;
	}
	int num=0;
	for(int i=0;i<8;i++) if(ary[i]) num++;

	if(!num) cout<<1<<" "<<sum<<endl;
	else cout<<num<<" "<<num+sum<<endl;
	return 0;
}
