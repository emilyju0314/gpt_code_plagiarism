#include<bits/stdc++.h>
using namespace std;
int n;
int ans,cnt;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        int a;
        scanf("%d",&a);
        if(a>cnt)
		{
			ans+=a-cnt;
		}
        cnt=a;
    }
    printf("%d",ans);
    return 0;
}