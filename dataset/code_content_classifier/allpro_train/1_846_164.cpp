#include<bits/stdc++.h>
using namespace std;
char M[52][52];
int main(void)
{
	int H,W;
	scanf("%d %d",&H,&W);
	for(int i=0;i<H;i++)
		scanf("%s",&M[i]);
	int tr=1;
	for(int i=0;i<H-1;i++)
	{for(int j=0;j<W-1;j++)
	{
		if(M[i][j]=='#'&&M[i][j+1]=='.'&&M[i+1][j]=='.'&&M[i][j-1]=='.'&&M[i-1][j]=='.') tr=0;
	}
	}
	if(tr) printf("Yes");
	else printf("No");
}