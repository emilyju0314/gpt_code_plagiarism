#include<stdio.h>
#include<algorithm>
using namespace std;
char str[110][110];
int deg[110][110];
int main(){
	int a;
	long long b;
	while(scanf("%d%lld",&a,&b),a){
		b--;
		if(a%2||(1LL<<(a/2))<=b){
			printf("No\n\n");
			continue;
		}
		for(int i=0;i<110;i++)for(int j=0;j<110;j++)
			str[i][j]=deg[i][j]=0;
		for(int i=0;i<a/2;i++){
			if(b&(1LL<<(a/2-1-i))){
				str[0][i*2]=str[0][i*2+1]='E';
			}else{
				str[0][i*2]=str[0][i*2+1]='.';
			}
		}
		for(int i=0;i<a;i++){
			if(i&&str[0][i]==str[0][i-1])deg[0][i]++;
			if(i<a-1&&str[0][i]==str[0][i+1])deg[0][i]++;
		}
		for(int i=1;i<a;i++){
			for(int j=0;j<a;j++){
				if(deg[i-1][j]<2){str[i][j]=str[i-1][j];deg[i][j]++;}
				else if(str[i-1][j]=='E')str[i][j]='.';
				else str[i][j]='E';
			}
			for(int j=0;j<a;j++){
				if(j&&str[i][j]==str[i][j-1])deg[i][j]++;
				if(j<a-1&&str[i][j]==str[i][j+1])deg[i][j]++;
			}
		}
		for(int i=0;i<a;i++)printf("%s\n",str[i]);
		printf("\n");
	}
}