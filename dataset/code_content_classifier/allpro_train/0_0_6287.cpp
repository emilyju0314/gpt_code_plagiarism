#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

#define MAXN 100005

int n;
int gender[MAXN];
int favNumber[MAXN];
vector<int> adjList[MAXN];
map<int, int> favCount[MAXN];

void dfs(int u, int p) {
    favCount[u][favNumber[u]] = 1;
    for (int v : adjList[u]) {
        if (v != p) {
            dfs(v, u);
            for (auto it : favCount[v]) {
                int num = it.first;
                int cnt = it.second;
                favCount[u][num] += cnt;
            }
        }
    }
}

int main() {
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> gender[i];
    }

    for (int i = 1; i <= n; i++) {
        cin >> favNumber[i];
    }

    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        adjList[a].push_back(b);
        adjList[b].push_back(a);
    }

    dfs(1, -1);

    int q;
    cin >> q;

    for (int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;

        map<int, int> commonFav;
        
        for (auto it : favCount[a]) {
            int num = it.first;
            int cnt = it.second;
            if (favCount[b].find(num) != favCount[b].end()) {
                commonFav[num] = min(cnt, favCount[b][num]);
            }
        }

        int ans = 0;
        for (auto it : commonFav) {
            ans += it.second;
        }

        cout << ans << endl;
    }

    return 0;
}