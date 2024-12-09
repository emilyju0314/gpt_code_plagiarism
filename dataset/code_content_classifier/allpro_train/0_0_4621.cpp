#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

const int MAXN = 305;
const int MAXE = 50005;

int n, v, e;
vector<pair<int, int>> tubes[MAXN];
int a[MAXN], b[MAXN], excess[MAXN];
int ans[MAXE][4], ans_size = 0;

bool dfs(int cur) {
    excess[cur] = 1;
    if(a[cur] == b[cur]) return true;

    for(auto& tube : tubes[cur]) {
        int next = tube.first;
        int& min_transfer = tube.second;

        if(excess[next] == 0 && min_transfer > 0) {
            int to_transfer = min(min_transfer, b[next] - a[next]);
            to_transfer = min(to_transfer, a[cur] - b[cur]);

            a[cur] -= to_transfer;
            a[next] += to_transfer;

            min_transfer -= to_transfer;
            ans[ans_size][0] = cur;
            ans[ans_size][1] = next;
            ans[ans_size++][2] = to_transfer;

            if(dfs(next)) return true;

            a[cur] += to_transfer;
            a[next] -= to_transfer;
            ans_size--;
        }
    }

    excess[cur] = 0;
    return false;
}

int main() {
    cin >> n >> v >> e;

    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for(int i = 1; i <= n; i++) {
        cin >> b[i];
    }

    for(int i = 0; i < e; i++) {
        int x, y;
        cin >> x >> y;
        int d;
        cin >> d;
        tubes[x].push_back({y, d});
        tubes[y].push_back({x, d});
    }

    if(dfs(1)) {
        cout << ans_size << endl;
        for(int i = 0; i < ans_size; i++) {
            cout << ans[i][0] << " " << ans[i][1] << " " << ans[i][2] << endl;
        }
    } else {
        cout << "NO" << endl;
    }

    return 0;
}