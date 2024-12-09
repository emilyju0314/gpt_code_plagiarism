#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pll pair<ll, ll>
#define pb push_back
#define pii pair<ll ,pll>
#define pi pair<pll, pll>
#define task "cf"
using namespace std;
const int N = 3e5+5;
const ll M = 1e6+5;
const ll mod = 1e15+7;
const ll base = 998244353;
ll n, t, m, k, tong, T, ans, a[N], d[N], b[N], c[N], sz[N];
vector<ll> kq, pre;
vector<ll> adj[N], val;
pll p[N];
string s;

void sol()
{
    cin >> T;
    while(T -- > 0)
    {
        cin >> n;
        ll pos = -1;
        kq.clear();
        for(int i = 2; i <= n; i ++)
        {
            cout <<"? "<< 1 <<" "<< i-1 <<endl;
            //fflush(stdout);
            cout << i << endl;
            //fflush(stdout);
            for(int j = 1; j < i; j ++)cout << j <<" ";
            cout << endl;
            //fflush(stdout);
            cin >> k;
            if(k != 0)
            {
                pos = i;
                break;
            }
        }
        for(int i = pos+1; i <= n; i ++)
        {
            cout <<"? "<< 1 <<" "<< 1 << endl;
            //fflush(stdout);
            cout << i <<endl;
            //fflush(stdout);
            cout <<pos<<endl;
            //fflush(stdout);
            cin >> k;
            if(k == 0)kq.pb(i);
        }
        ll lf = 1, rt = pos-1, mid;
        while(lf <= rt)
        {
            mid = (lf + rt) / 2;
            cout <<"? "<< 1 <<" "<<mid<<endl;
           // fflush(stdout);
            cout <<pos<<endl;
            //fflush(stdout);
            for(int j = 1; j <= mid; j ++)cout << j <<" ";
            cout << endl;
            //fflush(stdout);
            cin >> k;
            if(k != 0)rt = mid - 1;
            else lf = mid + 1;
        }
        for(int i = 1; i < lf; i ++)kq.pb(i);
        for(int i = 1+lf; i < pos; i ++)kq.pb(i);
        cout << "! " << kq.size()<<" ";
        for(ll x : kq)cout << x <<" ";
        cout << endl;
    }

}
int main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    if(fopen(task".inp", "r"))
    {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
    int ntest = 1;
    //cin >> ntest;
    while(ntest -- > 0)
    sol();
}
