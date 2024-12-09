#include <cstdio>
int bag[401][401],a[41],b[41],c[41];
int main()
{
    int N,Ma,Mb,ans;
    scanf("%d%d%d",&N,&Ma,&Mb);
    for(int i=0;i<N;i++)
        scanf("%d%d%d",&a[i],&b[i],&c[i]);
    for(int i=0;i<401;i++)
        for(int j=0;j<401;j++)
            bag[i][j]=-1;
    bag[0][0]=0;
    for(int i=0;i<N;i++)
        for(int j=400;j>=a[i];j--)
            for(int k=400;k>=b[i];k--)
                if(bag[j-a[i]][k-b[i]]!=-1&&(bag[j][k]==-1||bag[j][k]>bag[j-a[i]][k-b[i]]+c[i]))
                    bag[j][k]=bag[j-a[i]][k-b[i]]+c[i];
    ans=-1;
    for(int i=1;i<401;i++)
        if(i%Ma==0&&i/Ma*Mb<=400&&bag[i][i/Ma*Mb]!=-1)
            if(ans==-1||bag[i][i/Ma*Mb]<ans)
                ans=bag[i][i/Ma*Mb];
    printf("%d\n",ans);
    return 0;
}
