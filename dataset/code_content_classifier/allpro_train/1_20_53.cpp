#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int, int>
#define pll pair<long long, long long>
#define pb push_back
#define ff first
#define ss second
#define YES cout << "YES\n"
#define NO cout << "NO\n"
#define nn "\n"
#define sci(x) scanf("%d", &x)
#define LL_INF (1LL << 62)
#define INF (1 << 30)
#define SetBit(x, k) (x |= (1LL << k))
#define ClearBit(x, k) (x &= ~(1LL << k))
#define CheckBit(x, k) (x & (1LL << k))
#define mod 1000000007
#define N 200005

int arr[N];
int tree[4*N];

void init(int b, int e, int node = 1)
{
  if (b == e)
  {
    tree[node] = arr[b];
    return;
  }
  int left = node * 2;
  int right = node * 2 + 1;
  int mid = (b + e) / 2;
  init(b, mid, left);
  init(mid + 1, e, right);
  tree[node] = min(tree[left], tree[right]);
}

int query(int b, int e, int i, int j, int node = 1)
{
  if (b >= i && e <= j)
    return tree[node];
  if (b > j || e < i)
    return (INF);
  int left = node * 2;
  int right = node * 2 + 1;
  int mid = (b + e) / 2;
  return min(query(b, mid, i, j, left), query(mid + 1, e, i, j, right));
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;

        memset(arr, 0, sizeof(arr[0])*(n+3));
        
        for(int i = 0; i < 4*n+3; i++){
            tree[i] = INF;
        }

        ll x[n];
        for(int i = 0; i < n; i++){
            cin >> x[i];
            if(i>0) x[i] += x[i-1];
        }

        vector<pll> v;
        for(int i = 0; i < n; i++){
            v.pb({x[i], i});
        }

        sort(v.begin(), v.end());

        vector<ll> val, indx;

        for(int i = 0; i < n; i++){
            val.pb(v[i].ff);
            indx.pb(v[i].ss);
            arr[i+1] = v[i].ss;
        }

        init(1, n);

        ll sum = x[n-1];

        for(int i = 0; i < m; i++){
            int x;
            cin >> x;
            if(val.back() >= x){
                int p = lower_bound(val.begin(), val.end(), x) - val.begin();
                int z = query(1, n, p+1, n);
                cout << z << " ";
            }
            else {
                if(sum <= 0) cout << -1 << " ";
                else {
                    ll rem = x-val.back();
                    ll cnt = rem/sum;
                    if(rem%sum) cnt++;
                    ll ans = LL_INF;

                    ll need = x-cnt*sum;
                    // cout << need << ":" << val.back() << "***" << nn;
                    if(val.back() >= need){
                        int p = lower_bound(val.begin(), val.end(), need) - val.begin();
                        int z = query(1, n, p+1, n);
                        ans = cnt*n+z;
                    }

                    need = x-(cnt-1)*sum;
                    if(val.back() >= need){
                        int p = lower_bound(val.begin(), val.end(), need) - val.begin();
                        int z = query(1, n, p+1, n);
                        ans = min(ans, (cnt-1)*n+z);
                    }
                    cout << ans << " ";
                }
            }
        }

        cout << nn;

    }

    return 0;
}