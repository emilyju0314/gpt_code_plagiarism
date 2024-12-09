/*

                  ░██████╗░█████╗░██╗░░░██╗░██████╗░░█████╗░████████╗░█████╗░
                  ██╔════╝██╔══██╗██║░░░██║██╔════╝░██╔══██╗╚══██╔══╝██╔══██╗
                  ╚█████╗░██║░░██║██║░░░██║██║░░██╗░███████║░░░██║░░░███████║
                  ░╚═══██╗██║░░██║██║░░░██║██║░░╚██╗██╔══██║░░░██║░░░██╔══██║
                  ██████╔╝╚█████╔╝╚██████╔╝╚██████╔╝██║░░██║░░░██║░░░██║░░██║
                  ╚═════╝░░╚════╝░░╚═════╝░░╚═════╝░╚═╝░░╚═╝░░░╚═╝░░░╚═╝░░╚═╝

                                ███████████████████████████
                                ███████▀▀▀░░░░░░░▀▀▀███████
                                ████▀░░░░░░░░░░░░░░░░░▀████
                                ███│░░░░░░░░░░░░░░░░░░░│███
                                ██▌│░░░░░░░░░░░░░░░░░░░│▐██
                                ██░└┐░░░░░░░░░░░░░░░░░┌┘░██
                                ██░░└┐░░░░░░░░░░░░░░░┌┘░░██
                                ██░░┌┘▄▄▄▄▄░░░░░▄▄▄▄▄└┐░░██
                                ██▌░│██████▌░░░▐██████│░▐██
                                ███░│▐███▀▀░░▄░░▀▀███▌│░███
                                ██▀─┘░░░░░░░▐█▌░░░░░░░└─▀██
                                ██▄░░░▄▄▄▓░░▀█▀░░▓▄▄▄░░░▄██
                                ████▄─┘██▌░░░░░░░▐██└─▄████
                                █████░░▐█─┬┬┬┬┬┬┬─█▌░░█████
                                ████▌░░░▀┬┼┼┼┼┼┼┼┬▀░░░▐████
                                █████▄░░░└┴┴┴┴┴┴┴┘░░░▄█████
                                ███████▄░░░░░░░░░░░▄███████
                                ██████████▄▄▄▄▄▄▄██████████
                                ███████████████████████████

*/


#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <string>
#include<list>
#include <numeric>
#include <map>
#define ll long long
#define ul unsigned long long
#define modu 1000000007
#define f(i,j, n) for (ll i = j; i < n; ++i)
#define fo(i, j, n) for (ll i = j; i >=n; --i)
#define print(x) cout << x << endl
#define gi(x) scanf("%lld",&x)
#define gc(x) scanf("%s",&x)
#define ac(arr) accumulate(arr.begin(),arr.end(),0)
#define pb push_back
#define all(o) (o).begin(), (o).end()
#define F first
#define S second
using namespace std;


template<class t> using vi = vector<t>;
template<class t> using vvi = vi<vi<t>>;
// class  IslandInALake {
// public:
//     bool safe(int i, int j, vector<string>v) {
//         if (v[i][j] == '.' && v[i - 1][j] != '#' && v[i + 1][j] != '#' && v[i][j + 1] != '#' && v[i][j - 1] != '#')
//             return true;
//         return false;
//     }
//     bool connect(int i, int j, vector<string>v) {
//         if (v[i - 1][j] == '*' || v[i + 1][j] == '*' || v[i][j - 1] = '*' || v[i][j + 1] == '*' || v[i - 1][j - 1] = '*' || v[i + 1][j + 1] == '*' || v[i + 1][j - 1] == '*' || v[i - 1][j + 1] == '*')
//             return true;
//         return false;
//     }
//     int build(vector <string> country) {
//         int ans = 0;
//         for (int i = 0; i < country.size(); i++) {
//             for (int j = 0; j < country[i].size(); j++) {
//                 if (safe(i, j, std::vector<string> country)) {
//                     if (connect(i, j, vector<string>country)) {
//                         country[i][j] = '*';
//                         ans++;
//                     }
//                 }
//             }
//         }
//         return ans;
//     }
// };

void hinataVSsakura(void);
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    // For getting input from input.txt file
    freopen("input.txt", "r", stdin);

    // Printing the Output to output.txt file
    freopen("output.txt", "w", stdout);
#endif

    long long t = 1;
    // cin >> t;
    while (t--)
        hinataVSsakura();

#ifndef ONLINE_JUDGE
    cout << "\nTime Elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " sec\n";
#endif
    return 0;
}

struct jutsu {
    ll  a, b, c;
};

bool jutsu_compare(jutsu s1, jutsu s2) {
    return s1.a < s2.a;
}

ll ncr(ll n, ll k)
{
    ll res = 1;
    if (k > n - k)
        k = n - k;
    for (ll i = 0; i < k; ++i) {
        res *= (n - i);
        res /= (i + 1);
    }
    return res;
}

// vector<ll>prime(10000005, true);
// void seive(void) {
//     prime[1] = prime[0] = false;
//     for (ll i = 2; i <= 10000006; i++) {
//         if (prime[i]) {

//             for (ll j = i * i; j <= 10000006; j += i) {
//                 prime[j] = false;
//             }
//         }
//     }
// }

ll max(ll a, ll b)
{
    return (a > b) ? a : b;
}
ll min(ll a, ll b)
{
    return (a < b) ? a : b;
}

void swap(ll &a, ll &b) {
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
}
ll index(vector<ll>arr, ll val) {
    auto it = find(all(arr), val);
    if (it != arr.end()) {
        ll ind = it - arr.begin();
        return ind;
    }
    else return -1;
}

bool binarySearch(vector<ll>arr, ll val, ll i, ll j) {
    if (i > j)return 0;
    if (arr[i + ((j - i) / 2)] == val)return 1;
    if (arr[i + ((j - i) / 2)] < val)return binarySearch(arr, val, i + ((j - i) / 2) + 1, j);
    return binarySearch(arr, val, i, i + ((j - i) / 2) - 1);
}

bool valid(string x) {

    f(i, 0, x.size()) {
        if (x[i] != '4' || x[i] != '7')return false;
    }
    return true;
}

vi<ll>presum;
set<ll>suck;
vi<ll>arr;
void solve(ll s, ll e) {
    suck.insert(presum[e + 1] - presum[s ]);
    if (arr[s] == arr[e])return;
    ll l = s, h = e + 1;
    ll val = (arr[s] + arr[e]) / 2;
    while (l < h) {
        ll mid = (l + h) / 2;
        if (arr[mid] <= val) {
            l = mid + 1;
        }
        else h = mid;
    }
    ll p = h - 1;
    solve(s, p);
    solve(p + 1, e);
}
void hinataVSsakura(void)
{
    ll t ;
    cin >> t;
    while (t--) {
        ll n, q;
        cin >> n >> q;
        arr.resize(n, 0);
        f(i, 0, n)cin >> arr[i];
        sort(all(arr));
        suck.clear();
        presum.resize(n + 1, 0);
        f(i, 1, n + 1) {
            presum[i] = presum[i - 1] + arr[i - 1];
        }
        solve(0, n - 1);
        while (q--) {
            ll x;
            cin >> x;
            if (suck.count(x) != 0)print("Yes");
            else print("No");
        }

    }
}

