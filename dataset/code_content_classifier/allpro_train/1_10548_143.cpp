#include <iostream>
#include <cstdio>

using namespace std;

int n;
int a[200005];
int b[128];
int d[200005];
string s;
char c[200005];

int main()
{
    cin>>s;
    n = s.size();
    s = '.' + s;
    for(char i = 'a'; i <= 'z'; i++)
    {
        b[i] = n + 1;
    }
    for(int i = n; i >= 0; i--)
    {
        char mj;
        int mn = 1e9;
        for(char j = 'a'; j <= 'z'; j++)
        {
            if(a[b[j]] < mn)
            {
                mn = a[b[j]];
                mj = j;
            }
        }
        a[i] = mn + 1;
        c[i] = mj;
        d[i] = b[mj];
        b[s[i]] = i;
    }
    int now = 0;
    while(a[now] != 0)
    {
        putchar(c[now]);
        now = d[now];
    }
    return 0;
}
