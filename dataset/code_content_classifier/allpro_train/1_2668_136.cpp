#include <cstdio>
#include <cctype>
#define repu(i,x,y) for (int i=x; i<=y; ++i)
using namespace std;

int n,m,q,a[2010][2010],b[2010][2010],c[2010][2010];
char map[2010][2010];

int getint()
{
    char ch;
    while (!isdigit(ch=getchar()));
    int x=ch-'0';
    for (; isdigit(ch=getchar()); x=x*10+ch-'0');
    return x;
}

void calc(int (*a)[2010])
{
    repu(i,1,n)
        repu(j,1,m)
            a[i][j]+=a[i][j-1]+a[i-1][j]-a[i-1][j-1];
}

int query(int (*a)[2010],int x1,int y1,int x2,int y2)
{
    return a[x2][y2]-a[x1-1][y2]-a[x2][y1-1]+a[x1-1][y1-1];
}

int main()
{
    scanf("%d%d%d",&n,&m,&q);
    repu(i,1,n)
        scanf("%s",map[i]+1);
    repu(i,1,n)
        repu(j,1,m)
            if (a[i][j]=map[i][j]=='1')
            {
                b[i][j]=map[i][j+1]=='1';
                c[i][j]=map[i+1][j]=='1';
            }
    calc(a),calc(b),calc(c);
    while (q--)
    {
        int x1=getint(),y1=getint(),x2=getint(),y2=getint();
        printf("%d\n",query(a,x1,y1,x2,y2)-query(b,x1,y1,x2,y2-1)-query(c,x1,y1,x2-1,y2));
    }
    return 0;
}