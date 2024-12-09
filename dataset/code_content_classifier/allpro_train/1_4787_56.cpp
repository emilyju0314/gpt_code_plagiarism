/// Author :Nguyễn Thái Sơn -Ti20 -THPT chuyên Lương Thế Vinh

#include<bits/stdc++.h>
#define TASK "test"
#define ll long long
#define ull unsigned long long
#define fi first
#define se second
#define ti20_ntson int main()
#define all(x) (x).begin(),(x).end()
#define vi vector<int>
#define vii pair<int,int>

using namespace std;

const int oo = 1e9;
const int maxN = 35005;

int n,a[maxN],st[4*maxN],lazy[4*maxN],f[105][maxN],k,pre[maxN];

void build(int id, int l, int r)
{
    st[id] = oo;
    lazy[id] = 0;
    if (l == r) return;
    int mid = l+r >>1;
    build(id*2,l,mid);
    build(id*2+1,mid+1,r);
}

void nhap()
{
    cin >> n >> k;
    for (int i=1; i<=n; i++) cin >> a[i];
    for (int i=0; i<=n; i++)
        for (int j=0; j<=k; j++)
            f[j][i] = oo;
    f[0][0] = 0;
}

void down(int id)
{
    int s = lazy[id];
    st[id*2] +=s;
    lazy[id*2] +=s;
    st[id*2+1] +=s;
    lazy[id*2+1] +=s;
    lazy[id] =0;
}

void update(int id, int l, int r, int u, int v, int val)
{
    if (r < u || v < l) return;
    if (u <= l && r <= v){
        st[id] += val;
        lazy[id] += val;
        return;
    }
    int mid = l +r  >> 1;
    down(id);
    update(id * 2, l, mid, u, v, val);
    update(id * 2 + 1, mid + 1, r, u, v, val);
    st[id] = min(st[id * 2], st[id * 2 + 1]);
}

void tienxuli(int id, int l, int r, int u, int val)
{
    if (l > u || r< u) return;
    if (l == r && l == u) {
        st[id] = val;
        return;
    }
    int mid = l+r >>1;
    tienxuli(id*2,l,mid,u,val);
    tienxuli(id*2+1,mid+1,r,u,val);
    st[id] = min(st[id*2],st[id*2+1]);
}

int get(int id, int l, int r, int u, int v)
{
    if (l > v || r < u) return 1e9;
    if (l >= u && r <=v) return st[id];
    down(id);
    int mid = l+r >>1;
    return min (get(id*2,l,mid,u,v),get(id*2+1,mid+1,r,u,v));
}

void xuli(int z)
{
    build(1,0,n);
//    f[z][0] = 0;
    for (int i=0; i<=n; i++) {
//        if (z-1 == 0 && i == 0) cout << "YES";
        tienxuli(1,0,n,i,f[z-1][i]);
    }
    for (int i=1; i<=n; i++) {
        if (pre[a[i]] != 0) {
            update(1,0,n,0,pre[a[i]]-1,i-pre[a[i]]);
            }
            pre[a[i]] = i;
            f[z][i] = get(1,0,n,0,i-1);
//            f[z][i] = min (f[z][i],f[z-1][i-1]);
    }
    for (int i=1; i<=n; i++)
        pre[a[i]] =0;
}

void solve()
{
    for (int i=1; i<=k; i++) 
        xuli(i);
    cout << f[k][n];
}

ti20_ntson
{
ios_base::sync_with_stdio(false);cin.tie(0); cout.tie(0);
//freopen(TASK".INP","r",stdin);
//freopen(TASK".OUT","w",stdout);
int tv =1;
for (int i=1; i<=tv; i++) {
    nhap();
    solve();
    }
}

