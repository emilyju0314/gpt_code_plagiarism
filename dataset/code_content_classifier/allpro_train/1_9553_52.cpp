/*
    Author: Arjan Singh Bal, IIIT Gwalior
    "Everything in this world is magic, except to the magician"
*/

#include						<bits/stdc++.h>
#ifdef LOCAL
#include						"pprint.hpp"
#else
#define trace 					//
#endif

using namespace std;

template <typename Arg1>
void prn(Arg1&& arg1)
{ cout << arg1 << "\n"; }
template <typename Arg1, typename... Args>
void prn(Arg1&& arg1, Args&&... args)
{ cout << arg1 << " "; prn(args...); }

template <typename Arg1>
void prs(Arg1&& arg1)
{ cout << arg1 << " ";}
template <typename Arg1, typename... Args>
void prs(Arg1&& arg1, Args&&... args)
{ cout << arg1 << " "; prs(args...); }

template <typename Arg1>
void read(Arg1&& arg1)
{ cin >> arg1; }
template <typename Arg1, typename... Args>
void read(Arg1&& arg1, Args&&... args)
{ cin >> arg1; read(args...); }

#define ll						long long
#define pii						pair<int, int>
#define pli						pair<ll, int>
#define pil						pair<int, ll>
#define pll						pair<ll, ll>
#define vi						vector<int>
#define vll						vector<ll>
#define vb						vector<bool>
#define vd						vector<double>
#define vs						vector<string>
#define ff						first
#define ss						second
#define pb						push_back
#define eb						emplace_back
#define ppb						pop_back
#define pf						push_front
#define ppf						pop_front
#define vpii					vector<pii>
#define umap					unordered_map
#define all(x)					x.begin(),x.end()
#define clr(a,b)				memset(a,b,sizeof a)
#define fr(i, n)				for (int i = 0; i < n; ++i)
#define fr1(i, n)				for (int i = 1; i <= n; ++i)
#define rfr(i, n)				for (int i = n - 1; i >= 0; --i)
#define precise(x)				cout << fixed << setprecision(x)
typedef double					f80;

inline void solve();

signed main()
{
#ifdef LOCAL
    freopen("in.txt" , "r" , stdin);
    //freopen("out.txt" , "w" , stdout);
#else
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#endif
    
    int t = 1;
    read(t);
    fr1 (tc, t) {
        // cout << "Case #" << tc << ": ";
        solve();
    }
    return 0;
}

vector<vi> mat;

inline void solve()
{
    int n, m;
    read(n, m);

    mat.assign(n, vi(n));

    fr (i, n) {
        fr (j, n) {
            read(mat[i][j]);
            --mat[i][j];
        }
    }

    vi del(3, 0), per(3);
    iota(all(per), 0);
    
    string s;
    read(s);

    for (auto i : s) {
        if (i == 'R') {
            ++del[1];
        } else if (i == 'L') {
            --del[1];
        } else if (i == 'D') {
          ++del[0];
        } else if (i == 'U') {
          --del[0];
        } else if (i == 'I') {
          swap(del[1], del[2]);
          swap(per[1], per[2]);
        } else if (i == 'C') {
            swap(del[0], del[2]);
            swap(per[0], per[2]);
        }
    }

    trace(per, del);

    auto ans = mat;
    fr (i, n) {
        fr (j, n) {
            vi initCords = {i, j, mat[i][j]}, finCords(3);
            fr (k, 3) {
              finCords[k] = ((initCords[per[k]] + del[k]) % n + n) % n;
            }
            ans[finCords[0]][finCords[1]] = finCords[2] + 1;
        }
    }

    fr (i, n) {
        fr (j, n) {
            prs(ans[i][j]);
        }
        prn("");
    }
}
