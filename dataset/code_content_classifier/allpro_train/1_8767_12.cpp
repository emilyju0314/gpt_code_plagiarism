#include <bits/stdc++.h>
using namespace std;
#define boost ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL)
#define ll long long
#define tests ll test; cin >> test; while(test--)
#define fora(i, x, y) for (ll i = x; i <= y; ++i)
#define ford(i, x, y) for (ll i = x; i >= y; --i)
#define printlst(lst, x, y) fora(i, x, y) cout << lst[i] << " "; cout << endl;
#define inputlst(lst, x, y) fora(i, x, y) cin >> lst[i]
#define all(lst) lst.begin(), lst.end()
#define sortlst(lst) sort(all(lst))
#define setbits(n) __builtin_popcount(n)
#define sortarr(x, n, y) sort(x, x + n)
typedef pair<ll, ll> pl;
typedef pair<int, int> pi;
typedef vector<ll> vl;
typedef vector<int> vi;
typedef vector<vl> vovl;
typedef vector<vi> vovi;
typedef vector<string> vs;
typedef set<ll> sl;
typedef unordered_map<ll, ll> uml;
typedef map<ll, ll> ml;
#define forn(i, n) for (int i = 0; i < int(n); i++)

int calc(const vector<int> &a, const vector<int> &b){
    int n = a.size();
    int m = b.size();
    vector<int> su(n + 1);
    int r = m - 1;
    for (int i = n - 1; i >= 0; --i){
        su[i] = su[i + 1];
        while (r >= 0 && b[r] > a[i]) --r;
        if (r >= 0 && b[r] == a[i]) ++su[i];
    }
    int ans = 0;
    int j = 0;
    r = 0;
    forn(l, m){
        while (j < n && a[j] <= b[l] + j) ++j;
        while (r < m && b[r] - b[l] < j) ++r;
        ans = max(ans, r - l + su[j]);
    }
    return ans;
}

int main()
{
    boost;
    tests
    {
        ll m, n, x;
        cin >> n >> m;
        vi al, bl, ar, br;
        fora(i, 0, n - 1)
        {
            cin >> x;
            if (x < 0) al.push_back(-x);
            else ar.push_back(x);
        }
        fora(i, 0, m - 1)
        {
            cin >> x;
            if (x < 0) bl.push_back(-x);
            else br.push_back(x);
        }
        reverse(all(al)), reverse(all(bl));
        cout << calc(al, bl) + calc(ar, br) << "\n";
    }
    return 0;
} 