#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<cmath>
#include<vector>
#include<queue>
using namespace std;
#define mod 1000000007
#define maxn 100005
char s[maxn];
int num[maxn];
int all[maxn];
int main()
{
    scanf("%s",s);
    int len=strlen(s);
    for(int i=0;i<len;i++)
    {
        if(s[i]=='(')   num[i+1]=1;
        else num[i+1]=-1;
    }
    int temp=0;
    for(int i=1;i<=len;i++)
    {
        temp+=num[i];
        all[temp]++;
    }
    long long fin=0;
    temp=0;
    all[0]++;
    for(int i=1;i<=len;i++)
    {
        all[temp]--;
        fin+=all[temp];
        temp+=num[i];
    }
    printf("%lld\n",fin-1);
}