#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cctype>

#include <algorithm>
#include <unordered_map>
#include <random>
#include <bitset>
#include <queue>
#include <functional>
#include <set>
#include <map>
#include <vector>
#include <chrono>
#include <iostream>
#include <limits>
#include <numeric>

#define LOG(FMT...) fprintf(stderr, FMT)

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int main() {
#ifdef LBT
    freopen("test.in", "r", stdin);
    int nol_cl = clock();
#endif

    int N, M;
    scanf("%d%d", &N, &M);
    vector<int> C(N), cnt(M);
    for (int i = 0; i < N; ++i) {
        scanf("%d", &C[i]);
        ++cnt[--C[i]];
    }
    vector<vector<vector<int>>> G(2, vector<vector<int>>(M));
    vector<int> ans = cnt;
    for (int i = 1; i < N; ++i)
        if (C[i] != C[i - 1]) {
            G[i & 1][C[i]].push_back(C[i - 1]);
            G[i & 1][C[i - 1]].push_back(C[i]);
        }
    vector<vector<int>> adjAns(2, vector<int>(M));
    vector<int> ccnt(N + 1);
    for (int c : cnt) ++ccnt[c];
    int mx = *max_element(cnt.begin(), cnt.end());
    if (M > 1) {
        for (int t = 0; t <= 1; ++t) {
            for (int i = 0; i < M; ++i) {
                --ccnt[cnt[i]];
                for (int j : G[t][i]) {
                    --ccnt[cnt[j]--];
                    ++ccnt[cnt[j]];
                }

                // cerr << t << ' ' << i << ": "; for (int k = 0; k <= N; ++k) cerr << ccnt[k] << ' '; cerr <<
                // '\n';
                adjAns[t][i] = mx;
                while (!ccnt[adjAns[t][i]]) --adjAns[t][i];
                ++ccnt[cnt[i]];
                for (int j : G[t][i]) {
                    --ccnt[cnt[j]++];
                    ++ccnt[cnt[j]];
                }
            }
        }
    }
    for (int i = 1; i < N; ++i)
        if (C[i] != C[i - 1]) {
            ans[C[i]] = max(ans[C[i]], cnt[C[i]] + adjAns[!(i & 1)][C[i]]);
            ans[C[i - 1]] = max(ans[C[i - 1]], cnt[C[i - 1]] + adjAns[!(i & 1)][C[i - 1]]);
        }

    for (int i = 0; i < M; ++i) printf("%d\n", N - ans[i]);

#ifdef LBT
    LOG("Time: %dms\n", int((clock() - nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
    return 0;
}
