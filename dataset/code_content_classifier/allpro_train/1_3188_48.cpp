#include<stdio.h>
#include<algorithm>
using namespace std;
char str[101];
char c[2];
int p[100];
int ABS(int a){return a<0?-a:a;}
int main(){
	int a,b;
	while(scanf("%d%d",&a,&b),a+b){
		for(int i=0;i<a;i++)str[i]='#';
		str[a]=0;
		bool ok;
		for(int i=0;i<b;i++){
			scanf("%s",c);
			switch(c[0]){
				case 'A':
					for(int j=0;j<a;j++)
						if(str[j]=='#'){
							str[j]='A';
							break;
						}
					break;
				case 'B':
					ok=false;
					for(int j=a-1;j>=0;j--){
						if(str[j]=='#'&&(j==0||str[j-1]!='A')&&str[j+1]!='A'){
							ok=true;
							str[j]='B';
							break;
						}
					}
					if(!ok){
						for(int j=0;j<a;j++)
							if(str[j]=='#'){
								str[j]='B';
								break;
							}
					}
					break;
				case 'C':
					if(i==0){
						str[a/2]='C';
					}else{
						for(int j=0;j<a;j++){
							if(str[j]!='#'){
								if(str[j+1]=='#'){
									str[j+1]='C';
									break;
								}else if(j&&str[j-1]=='#'){
									str[j-1]='C';
									break;
								}
							}
						}
					}
					break;
				case 'D':
					for(int j=0;j<a;j++)p[j]=9999;
					for(int j=0;j<a;j++){
						if(str[j]!='#'){
							for(int k=0;k<a;k++)p[k]=min(p[k],ABS(j-k));
						}
					}
					int at=0;
					int cost=0;
					for(int j=0;j<a;j++){
						if(cost<p[j]){at=j;cost=p[j];}
					}
					str[at]='D';
					break;
			}
			//	printf("%s\n",str);
		}
		printf("%s\n",str);
	}
}