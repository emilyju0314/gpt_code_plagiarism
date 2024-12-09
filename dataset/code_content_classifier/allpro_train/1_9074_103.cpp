#include<string>
#include<string.h>
#include<map>
#include<set>
#include<vector>
#include<stdio.h>
#include<math.h>
#include<iostream>
#include<algorithm>
#include<queue>
#include<stdio.h>
#define fo(i,a,b)for(int i(a);i<(b);i++)
#define rep(i,n)fo(i,0,n)
using namespace std;
#define pii pair<int,int>
#define ll long long
#define mp make_pair
#define pb push_back
typedef pair<pair<int,int>,int>tri;

char s[500005];
int cnt[500005];
int ans[500005];
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    cin>>s[i];
    for(int i=1;i<=n;i++)
    if(s[i]=='0')cnt[i]=i;
    else cnt[i]=cnt[i-1];
    for(int i=1;i<=n;i++)
    {
        ans[i]=ans[i-1];
        if(s[i]=='1')
        {
            if(s[i-1]=='0' && s[i-2]=='1')
            {
                ans[i]=max(ans[i],ans[cnt[i-2]]+i-2-cnt[i-2]);
                ans[i]=max(ans[i],ans[cnt[i-2]+1]+i-2-cnt[i-2]-1);
            }
            if(s[cnt[i]-1]=='1')
            {
                ans[i]=max(ans[i],ans[cnt[i]-2]+i-cnt[i]);
            }
        }
    }
    cout<<ans[n];
    return 0;
}
