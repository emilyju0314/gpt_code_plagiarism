# include "iostream"
# include "cstdio"

using namespace std;

int N,K;

int main(){
	scanf("%d%d",&N,&K);
	puts((N+1)/2>=K?"YES":"NO");
	return 0;
}