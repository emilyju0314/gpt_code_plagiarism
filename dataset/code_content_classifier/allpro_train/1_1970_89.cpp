#include<bits/stdc++.h>

using namespace std;

#define ll  long long
#define ld  double

#define sz(x)   (int)x.size()
#define all(x)  x.begin(),x.end()

#define pb  emplace_back
#define X   first
#define Y   second

const int   N   = 5e5 + 5;
const int   mod = 998244353;

void add(int &a,int b)  {
    a += b;
    if (a >= mod)
        a -= mod;
}
void sub(int &a,int b)  {
    a -= b;
    if (a <  0)
        a += mod;
}
int mul(int a,int b)    {
    return  1ll * a * b % mod;
}
int Pow(int a,int b)    {
    int ans = 1;
    while (b)   {
        if(b & 1)   ans = mul(ans,a);
        a = mul(a,a);   b >>= 1;
    }
    return  ans;
}
int inv(int a,int p)    {
    return  a == 1 ? 1 : p - 1ll * p * inv(p % a,a) / a;
}
int Fac[N];
int Inv[N];

int Ckn(int n,int k)    {
    if (n < k)  return  0;
    if (k < 0)  return  0;

    return  mul(Fac[n],mul(Inv[k],Inv[n - k]));
}

typedef pair<int,int>   ii;

int main()  {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    Fac[0] = Inv[0] = 1;

    for(int i = 1 ; i < N ; ++i)    Fac[i] = mul(Fac[i - 1],i);     Inv[N - 1] = inv(Fac[N - 1],mod);
    for(int i = N - 2 ; i ; --i)    Inv[i] = mul(Inv[i + 1],i + 1);

    int n;  cin >> n;
    int m;  cin >> m;

    if (n > m)
        swap(n,m);

    int ans = 0;

    for(int i = 0 ; i <= n ; ++i)   {
        int cur = Fac[i];

        cur = mul(cur,Ckn(n,i));
        cur = mul(cur,Ckn(m,i));

        cur = mul(cur,Pow(n + 1,m - i));
        cur = mul(cur,Pow(m + 1,n - i));

        if (i & 1)  sub(ans,cur);
        else        add(ans,cur);
    }
    cout << ans << endl;
}