#pragma GCC optimize("Ofast")
#include<cstdio>
#include<cstring>
int main(){
	char s[100001];
	int i,a=0,b=0;
	scanf("%s",s);
	for(i=0;i<strlen(s);i++){
		if(i%2){if(s[i]-49)a++; else b++;}
		else{if(s[i]-48)a++; else b++;}
	}
	printf("%d",a>b?b:a);
}