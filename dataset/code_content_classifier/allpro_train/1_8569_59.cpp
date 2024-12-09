//created by missever

#include<bits/stdc++.h>
#define MAX 1000000007
using namespace std;

char s[111];
pair<int,int>p[111];
bool vis[111];

int main()
{
    int n,i,j,k;
    int len,t,x,y,w = 0;
    scanf("%d",&n);
    for(i = 0; i < n; i++)
    {
        scanf("%s",s);
        len = strlen(s);
        x = t = 0;
        for(j = 0; j < len; j++)
        {
            if(s[j] == '(') t++;
            else if(t)
            {
                t--;
                x++;
            }
        }
        p[i].second = t;
        p[i].first = len - 2 * x - t;
    }
    y = 0;
    for(i = 0; i < n; i++)
    {
        if(p[i].second == 0 && p[i].first > 0)
        {
            y += p[i].first;
            vis[i] = 1;
            w++;
        }
    }
    x = 0;
    while(w < n)
    {
        t = -1000;
        for(j = 0; j < n; j++)
        {
            if(!vis[j])
            {
                if((x - p[j].first >= 0) && (p[j].second - p[j].first > t))
                {
                    k = j;
                    t = p[j].second - p[j].first;
                }
            }
        }
        if(t != -1000)
        {
            vis[k] = 1;
            x += t;
        }
        else
        {
            printf("No\n");
            return 0;
        }
        w++;
        //cout<<x<<endl;
    }
    if(x != y) printf("No\n");
    else printf("Yes\n");
    return 0;
}