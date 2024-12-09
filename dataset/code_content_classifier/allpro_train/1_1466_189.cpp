#include<iostream>
#include<cmath>
#include<cstring>

#define rep(i,n) for(int i=0; i<n; i++)
#define MAX 1000000

char p[MAX];

int main(){

	memset(p,1,sizeof(p));

	p[0] = 0;
	p[1] = 0;

	for(int i=2;i<sqrt(MAX)+1;i++){
		for(int j=i*2;j<MAX; j+=i){
			if(p[j])p[j]=0;
		}
	}
	int a,d,n;
	int cnt;
	while(std::cin >> a >> d >> n,(a||d||n)){
		cnt = 0;
		while(1){
			if(p[a]){
				cnt++;
				if(cnt == n)break;
			}
			a += d;
		}
		std::cout << a << std::endl;
	}
	return 0;
}