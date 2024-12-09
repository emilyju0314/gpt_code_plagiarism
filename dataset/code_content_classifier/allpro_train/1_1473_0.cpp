#include <iostream>
#include <cstdio>
#include <cassert>
#include <cstring>
#include <vector>
#include <valarray>
#include <array>
#include <queue>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <cmath>
#include <complex>
#include <random>
#include <bitset>
#include <stack>

using namespace std;
using ll = long long;
using ull = unsigned long long;

using P = pair<int, int>;

using T = pair<P, int>;

vector<T> sv, tv;

const int W = 4040;
int dp[W][W][4][2];
bool used[W][W][4][2];

int solve(int i, int j, int k, int f) {
//    printf("%d %d %d %d\n", i, j, k, f);
    if (i == sv.size() and j == tv.size()) return 0;
    if (j == tv.size()) return 1<<28;
    k = min(k, tv[j].first.first+2);
    k = max(k, tv[j].first.first-1);
    int kf = k - (tv[j].first.first-1);
    if (used[i][j][kf][f+1]) return dp[i][j][kf][f+1];
    used[i][j][kf][f+1] = true;
    int &re = dp[i][j][kf][f+1];
    re = 1<<28;
    if (tv[j].second == 1) {
        re = min(re, solve(i, j+1, k, f));
    }
    if (i == sv.size()) return re;
    if (tv[j].first.first < sv[i].first.first) {
        int u = sv[i].first.first - tv[j].first.first;
        if (tv[j].first.first == sv[i-1].first.first && f != -1) {
            u--;
        }
        re = min(re, u + solve(i+1, j+1, sv[i].first.first, -1));
    } else if (sv[i].first.first < tv[j].first.first) {
        int u = tv[j].first.first - sv[i].first.first;
        if (sv[i].first.first == sv[i-1].first.first && f != -1) {
            u--;
        }
        re = min(re, u + solve(i+1, j+1, tv[j].first.first, -1));
    } else {
        if (sv[i].first.second == tv[j].first.second) {
            re = min(re, solve(i+1, j+1, k, -1));
        } else {
            if ((f == -1 || sv[i-1].first.second != sv[i].first.second) && tv[j].first.first <= k) {
                re = min(re, solve(i+1, j+1, k, -1));
            } else {
                re = min(re, 1+solve(i+1, j+1, sv[i].first.first+1, 0));
            }
        }
    }
    return re;
}

int main() {
    int w;
    cin >> w;
    for (int i = 0; i < 2; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < w; j++) {
            if (s[j] == 'o') {
                sv.push_back(T(P(j, i), 0));
            }
        }
    }

    for (int i = 0; i < 2; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < w; j++) {
            if (s[j] == 'o') {
                tv.push_back(T(P(j, i), 0));
            } else if (s[j] == '*') {
                tv.push_back(T(P(j, i), 1));
            }
        }
    }
    sort(sv.begin(), sv.end());
    sort(tv.begin(), tv.end());
//    cout << sv.size() << " " << tv.size() << endl;
    cout << solve(0, 0, -1, -1) << endl;
    return 0;
}