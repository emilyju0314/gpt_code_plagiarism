#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<set<int>> friends(n+1);
    vector<int> count(n+1, 0);

    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        friends[x].insert(y);
        friends[y].insert(x);
        count[x]++;
        count[y]++;
    }

    set<int> q;
    for (int i = 1; i <= n; i++) {
        if (count[i] < k) {
            q.insert(i);
        }
    }

    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        if (friends[x].count(y)) {
            if (q.count(x)) {
                q.erase(x);
            }
            if (q.count(y)) {
                q.erase(y);
            }
        }

        cout << q.size() << "\n";
    }

    return 0;
}