#include<cstring>
#include<cstdio>
using namespace std;
int l,i;
char s[110];
bool a=0;
int main(){
	scanf("%s",s);
	l=strlen(s);
	for(i=0;i<l;i++){
		if(!a&&s[i]=='C') a=1;
		if(a&&s[i]=='F'){printf("Yes");return 0;}
	}
	printf("No");
}