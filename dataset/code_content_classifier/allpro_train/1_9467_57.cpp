#include <bits/stdc++.h>
using namespace std;
namespace Flandre_Scarlet
{
    #define N 1502
    #define F(i,l,r) for(int i=l;i<=r;++i)
    #define D(i,r,l) for(int i=r;i>=l;--i)
    #define Fs(i,l,r,c) for(int i=l;i<=r;c)
    #define Ds(i,r,l,c) for(int i=r;i>=l;c)
    #define MEM(x,a) memset(x,a,sizeof(x))
    #define FK(x) MEM(x,0)
    #define Tra(i,u) for(int i=G.st(u),v=G.to(i);~i;i=G.nx(i),v=G.to(i))
    #define p_b push_back
    #define sz(a) ((int)a.size())
    #define all(a) a.begin(),a.end()
    #define iter(a,p) (a.begin()+p)
    #define PUT(a,n) F(i,1,n) printf("%d ",a[i]); puts("");
    int I() {char c=getchar(); int x=0; int f=1; while(c<'0' or c>'9') f=(c=='-')?-1:1,c=getchar(); while(c>='0' and c<='9') x=(x<<1)+(x<<3)+(c^48),c=getchar(); return ((f==1)?x:-x);}
    template <typename T> void Rd(T& arg){arg=I();}
    template <typename T,typename...Types> void Rd(T& arg,Types&...args){arg=I(); Rd(args...);}
    void RA(int *p,int n) {F(i,1,n) *p=I(),++p;}
    int n,q;
    int a[N][N];
    void Input()
    {
        Rd(n,q);
        F(i,1,n) F(j,1,n)
        {
            a[i][j]=I();
        }
    }
    struct node
    {
        int x,y,d; // d: 切比雪夫距离
    };
    bool cmp_pos(node a,node b) {return a.x<b.x or (a.x==b.x and a.y<b.y);}
    bool cmp_d(node a,node b) {return a.d<b.d;}
    vector<node> rec[N][N];
    node t[35];
    int mxlen[N][N];
    inline int cheb(int x1,int y1,int x2,int y2) {return max(abs(x1-x2),abs(y1-y2))+1;}
    bool vis[N*N];
    int cf[N];
    void Sakuya()
    {
        FK(vis); FK(t);
        F(i,1,n) F(j,1,n)
        {
            node cur=(node){i,j,1};
            int tpos=0;
            t[++tpos]=cur;
            if (j>1) for(auto x:rec[i][j-1]) t[++tpos]=((node){x.x,x.y,cheb(x.x,x.y,i,j)});
            if (i>1) for(auto x:rec[i-1][j]) t[++tpos]=((node){x.x,x.y,cheb(x.x,x.y,i,j)});
            if (i>1 and j>1) for(auto x:rec[i-1][j-1]) t[++tpos]=((node){x.x,x.y,cheb(x.x,x.y,i,j)});
            sort(t+1,t+tpos+1,cmp_d);
            int tot=0;
            mxlen[i][j]=114514;
            rec[i][j].clear();
            F(ii,1,tpos)
            {
                node x=t[ii];
                int c=a[x.x][x.y];
                if (!vis[c])
                {
                    vis[c]=1;
                    rec[i][j].p_b(x);
                    ++tot;
                    if (tot==q+1)
                    {
                        mxlen[i][j]=x.d-1;
                        break;
                    }
                }
            }
            mxlen[i][j]=min({mxlen[i][j],i,j});

            F(ii,1,tpos) 
            {
                node x=t[ii];
                vis[a[x.x][x.y]]=0;
            }

            // printf("i=%d j=%d\n",i,j);
            // printf("mxlen=%d\n",mxlen[i][j]);
            // puts("");
        }
        F(i,1,n) F(j,1,n)
        {
            ++cf[0]; --cf[mxlen[i][j]+1];
        }
        F(i,1,n) cf[i]+=cf[i-1];
        F(i,1,n) printf("%d\n",cf[i]);
    }
    void IsMyWife()
    {
        Input();
        Sakuya();
    }
}
#undef int //long long
int main()
{
    Flandre_Scarlet::IsMyWife();
    getchar();
    return 0;
}
	  			   		  			 	  			 	 	   	