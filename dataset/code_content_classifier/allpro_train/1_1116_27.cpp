#include <iostream>
using namespace std;
#define MAX_N 4000

int num[MAX_N/2+1];

int main(int argc, char const *argv[])
{
	// a+b=nの(a,b)の組み合わせ数を計算 0<=a<=1000, 0<=b<=1000
	for(int i=0;i<=MAX_N/4;i++){
		for(int j=0;j<=MAX_N/4;j++){
			num[i+j]++;
		}
	}
	int n;
	while(cin>>n){
		int ans=0;
		for(int i=0;i<=MAX_N/2;i++){
			int cd = n-i;
			if(cd<0)break;
			if(cd>2000)continue;
			ans += num[i] * num[cd];
		}
		cout<<ans<<endl;
	}
	return 0;
}