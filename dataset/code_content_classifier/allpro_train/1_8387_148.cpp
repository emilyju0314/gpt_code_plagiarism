#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

map <int, vector <int> > mp;

int a[100010];
int ans[100010];
int pptr[100010];
bool u[100010];
int ptr[1000010];

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i < n; ++i) {
        mp[0].push_back(i);
    }
    int q;
    cin >> q;
    for (int i = q; i >= 1; --i) {
        cin >> a[i];
    }
    int cnt = 1;
    for (int i = 1; i <= q; ++i) {
        if (!u[a[i]]) {
            ans[cnt] = a[i];
            pptr[a[i]] = cnt;
            ++cnt;
            u[a[i]] = 1;
        } else {
            if (mp.find(pptr[a[i]] - 1) == mp.end() || mp[pptr[a[i]] - 1].empty()) {
                continue;
            } else {
                mp[pptr[a[i]]].push_back(mp[pptr[a[i]] - 1].back());
                mp[pptr[a[i]] - 1].pop_back();
                if (mp[pptr[a[i]] - 1].empty()) {
                    mp.erase(pptr[a[i]] - 1);
                }
            }
        }
    }
    vector <int> help;
    int mn = mp.begin()->first;
    for (int i = 1; i <= mn; ++i) {
        help.push_back(ans[i]);
    }
    sort(help.begin(), help.end());
    int qqwe = 0;
    int qsr = 1;
    ++mn;
    for (; mn < cnt; ++mn) {
        while (qqwe < help.size() && qsr == help[qqwe]) {
            ++qsr;
            ++qqwe;
        }
        if (ans[mn] != qsr) {
            cout << "No\n";
            return 0;
        }
        ++qsr;
    }
    cout << "Yes\n";
    return 0;
}
