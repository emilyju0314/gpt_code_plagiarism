    /*Design by Dinh Viet Anh(JOKER)*/
//_____________________________________$$$$$__
//___________________________________$$$$$$$$$
//___________________________________$$$___$
//___________________________$$$____$$$$
//_________________________$$$$$$$__$$$$$$$$$$$
//_______________________$$$$$$$$$___$$$$$$$$$$$
//_______________________$$$___$______$$$$$$$$$$
//________________$$$$__$$$$_________________$$$
//_____________$__$$$$__$$$$$$$$$$$_____$____$$$
//__________$$$___$$$$___$$$$$$$$$$$__$$$$__$$$$
//_________$$$$___$$$$$___$$$$$$$$$$__$$$$$$$$$
//____$____$$$_____$$$$__________$$$___$$$$$$$
//__$$$$__$$$$_____$$$$_____$____$$$_____$
//__$$$$__$$$_______$$$$__$$$$$$$$$$
//___$$$$$$$$$______$$$$__$$$$$$$$$
//___$$$$$$$$$$_____$$$$___$$$$$$
//___$$$$$$$$$$$_____$$$
//____$$$$$$$$$$$____$$$$
//____$$$$$__$$$$$___$$$
//____$$$$$___$$$$$$
//____$$$$$____$$$
//_____$$$$
//_____$$$$
//_____$$$$
#include <stdio.h>
#include <stdlib.h>
#define maxn 1000010
#define maxm 10000005
#define maxc 1000000007
#define mp make_pair
#define pb push_back
#define F first
#define S second
#define pii pair<ll, ll>
#define fort(i, a, b) for(int i = (a); i <= (b); i++)
#define ford(i, a, b) for(int i = (a); i >= (b); i--)
#define Task ""
#define stop1 {cout << "-1\n"; return;}
#define stop2 {cout << "NO\n"; return;}
#define stop3 {cout << "YES\n"; return;}
#define ll long long
#define mid (l+r)/2
#define JOKER main

int a[maxn], n;

void setup()
{

}

int min(int x, int y)
{
    return (x > y) ? y : x;
}

int max(int x, int y)
{
    return (x < y) ? y : x;
}

void work()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
        fort(i, 1, n)
            scanf("%d", &a[i]);
        int res = 0;
        fort(i, 1, n-1)
        {
            while(min(a[i+1], a[i]) * 2 < max(a[i], a[i+1]))
            {
                res += 1;
                if(a[i] > a[i+1])
                    a[i] = (a[i] + 1) / 2;
                else
                    a[i] *= 2;
            }
        }
        printf("%d\n", res);
    }
}

int main()
{
    //freopen(Task".inp", "r", stdin);
    //freopen(Task".out", "w", stdout);
    setup();
    work();
    return 0;
}
