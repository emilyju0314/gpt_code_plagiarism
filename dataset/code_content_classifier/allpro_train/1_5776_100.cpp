#include<bits/stdc++.h>
using namespace std;
int c;
int main()
{
	scanf("%d",&c);
	for(int i=1;i<=9;i++) for(int j=i;j<=9;j++) if(c==i*j) return puts("Yes"),0;
	puts("No");
}