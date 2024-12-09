#include<bits/stdc++.h>

int main()
{
	char s[5];
	scanf("%s",s);

	int x=(s[0]-48)*10+s[1]-48,y=(s[2]-48)*10+s[3]-48;

	if(x>0 && x<=12 && y>0 && y<=12)printf("AMBIGUOUS\n");
	else if(x>0 && x<=12)printf("MMYY\n");
	else if(y>0 && y<=12)printf("YYMM\n");
	else printf("NA\n");

	return 0;
}
