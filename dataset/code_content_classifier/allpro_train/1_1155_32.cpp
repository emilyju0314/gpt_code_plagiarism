#include <bits/stdc++.h>
using namespace std;
#define IOS                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define pb push_back
#define pf push_front
#define pob pop_back
#define pof pop_front
#define eb emplace_back
#define mp make_pair
#define nl cout << "\n";
#define ff first
#define ss second
#define rp(i, a, b) for (long long int i = a; i < b; i++)
#define inp(A) rp(i, 0, sizeof(A) / sizeof(A[0])) cin >> A[i];
#define outp(A)                                             \
    rp(i, 0, sizeof(A) / sizeof(A[0])) cout << A[i] << " "; \
    nl;
#define pr(x) cout << (#x) << " " << (x) << endl;
#define all(v) v.begin(), v.end()
#define MOD 1000000007

typedef long long int ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<string> vs;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;

void solve()
{
    ll a, b, k; cin >> a >> b >> k;
    ll A[k], B[k];
    unordered_map<ll, ll> ma, mb;
    rp(i, 0, k) {
        cin >> A[i];
        ma[A[i]]++;
    }
    rp(i, 0, k) {
        cin >> B[i];
        mb[B[i]]++;
    }

    ll count = 0;
    rp(i, 0, k) {
        count += (k-ma[A[i]]-mb[B[i]] + 1);
        // cout << count << " ";
    }

    cout << count/2;

    nl;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    IOS;
    int T = 1;
    cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}