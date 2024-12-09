#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=4e5+5;
typedef long long ll;
int n,k;
char s[N];
int num[N];
int st;
int main()
{
    scanf("%d%d",&n,&k);
    scanf("%s",s+1);
    for(int i=1;i<=n;i++)
        num[i]=s[i]-'A';
    st=num[1];
    int p=1;
    int cnt=0;//p表示删到哪里了，cnt是操作次数
    while(k--){
        if(st==0){//这是第一个是A的情况
            st^=1;
            num[p]^=1;
        }
        else{
            p++;
            cnt++;
            st=num[p];
            st^=(cnt&1);
        }
        if(p>n)
            break;
    }
    if(p<=n){
        for(int i=p;i<=n;i++)
            putchar('A'+(num[i]^(cnt&1)));
        int t=p-1,c=(cnt-1)&1;
        while(t--){
            putchar('A'+c);
            c^=1;
        }
    }
    else{
        if((cnt-1)&1)//BABA
            for(int i=1;i<=n;i++)
                putchar('A'+(i&1));
        else{//ABAB
            putchar('A'+(k&1));
            for(int i=1;i<n;i++)
                putchar('A'+(i&1));
        }
    }
}