#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> g(n+1);
    for (int i = 1; i <= n; i++) {
        cin >> g[i];
    }

    vector<int> v(m+1);
    vector<int> b(m+1);
    for (int i = 1; i <= m; i++) {
        cin >> v[i];
    }

    for (int i = 1; i <= m; i++) {
        cin >> b[i];
    }

    vector<int> res(m+1, 0);
    vector<int> last(n+1, 0);
    for (int i = 1; i <= m; i++) {
        int cur = i;
        while (b[cur] > 0) {
            res[cur]++;
            int next = (last[cur] + v[cur] - 1) % n + 1;
            last[cur] = next;
            cur = next;
            b[cur]--;
        }
    }

    for (int i = 1; i <= m; i++) {
        if (i != 1) {
            cout << res[i] << endl;
        }
    }

    return 0;
}