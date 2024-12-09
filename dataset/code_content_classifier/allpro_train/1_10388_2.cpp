#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cctype>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <algorithm>
#include <iostream>
#include <string>
#include <set>
#define X first
#define Y second
#define sqr(x) (x)*(x)
using namespace std;
const double PI = acos(-1.0);
map<int,int>::iterator it;
typedef long long LL ;
#pragma comment(linker,"/STACK:102400000,102400000")

struct face
{
    int p[3][3];
    face rotate_left()
    {
        face ret;
        for(int i=0;i<3;++i)
        {
            for(int j=0;j<3;++j)
            {
                ret.p[2-j][i]=p[i][j];
            }
        }
        return ret;
    }
    face rotate_right()
    {
        face ret = rotate_left();
        ret = ret.rotate_left();
        ret = ret.rotate_left();
        return ret;
    }
    void input()
    {
        char s[5][5];
        for(int i=0;i<3;++i)
        {
            scanf("%s",s[i]);
        }
        for(int i=0;i<3;++i)
        {
            for(int j=0;j<3;++j)
            {
                p[i][j]=(s[i][j]=='.')?0:1;
            }
        }
    }
    void pf()
    {
        for(int i=0;i<3;++i)
        {
            for(int j=0;j<3;++j)
            {
                printf("%d",p[i][j]);
            }
            puts("");
        }
    }
};




struct cube
{
    face f[8];
    int dis;
    cube left()
    {
        cube ret ;
        ret.f[0] = (*this).f[0].rotate_left();
        ret.f[1] = (*this).f[5].rotate_right();
        ret.f[2] = (*this).f[2].rotate_right();
        ret.f[3] = (*this).f[4].rotate_right();
        ret.f[4] = (*this).f[1].rotate_right();
        ret.f[5] = (*this).f[3].rotate_right();
        return ret;
    }
    cube right()
    {
        cube ret;
        ret.f[0] = (*this).f[0].rotate_right();
        ret.f[1] = (*this).f[4].rotate_left();
        ret.f[2] = (*this).f[2].rotate_left();
        ret.f[3] = (*this).f[5].rotate_left();
        ret.f[4] = (*this).f[1].rotate_left();
        ret.f[5] = (*this).f[3].rotate_left();
        return ret;
    }
    cube forward()
    {
        cube ret;
        ret.f[0] = (*this).f[5];
        ret.f[1] = (*this).f[1].rotate_right();
        ret.f[2] = (*this).f[4].rotate_left();
        ret.f[2] = ret.f[2].rotate_left();
        ret.f[3] = (*this).f[3].rotate_left();
        ret.f[4] = (*this).f[0];
        ret.f[5] = (*this).f[2].rotate_left();
        ret.f[5] = ret.f[5].rotate_left();
        return ret;
    }
    cube back()
    {
        cube ret = (*this).forward();
        ret = ret.forward();
        ret = ret.forward();
        return ret;
    }
    bool good()
    {
        bool ok1=0,ok2=0;
        for(int i=0;i<3;++i)
        {
            if(f[0].p[2][i]==1)ok1=1;
            if(f[2].p[2][i]==1)ok2=1;
        }
        return ok1&&ok2;
    }
    void pf()
    {
        for(int i=0;i<6;++i)
        {
            f[i].pf();
        }
    }
};
cube C;
int res;
void dfs(cube u,int depth)
{
    if(depth>9)return ;
    if(u.good())
    {
        //printf("d = %d\n",depth);
        res = min(res,depth);
    }
    else
    {
        cube v = u.back();
        dfs(v,depth+1);
        v = u.forward();
        dfs(v,depth+1);
        v = u.left();
        dfs(v,depth+1);
        v = u.right();
        dfs(v,depth+1);
    }
}
int main()
{
    char s[8][8];
//    face ff;
//    ff.input();
//    ff.pf();
//    ff=ff.rotate_left();
//    ff.pf();
//    ff=ff.rotate_left();
//    ff.pf();

    while(1)
    {
        scanf("%s",s[0]);
        if(s[0][0]=='#')break;
        for(int i=1;i<3;++i)scanf("%s",s[i]);
        for(int i=0;i<3;++i)
        {
            for(int j=0;j<3;++j)
            {
                C.f[0].p[i][j]=(s[i][j]=='.')?0:1;
            }
        }
        for(int i=1;i<6;++i)C.f[i].input();
        //puts("OK");
        res=10000;
        //C.f[0].pf();
        //C.f[2].pf();
//        C.pf();
//        C = C.left();
//        puts("");
//        C.pf();
//        C = C.right();
//        puts("");
//        C.pf();
        dfs(C,0);
        printf("%d\n",res);
    }
	return 0;
}