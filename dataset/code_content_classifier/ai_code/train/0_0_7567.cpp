#include <iostream>
#include <vector>
#include <set>

using namespace std;

int n, m;
vector<int> cnt(7001);
vector<vector<int>> left(7001, vector<int>(7001, -1));
vector<vector<int>> right(7001, vector<int>(7001, -1));
vector<set<int>> sets(7001);

void addValue(int t, int l, int r, int x) {
    for (int position = l; position <= r; position++) {
        sets[t].insert(x);
    }
}

int findUnion(int t, int v) {
    set<int> unionSet;
    vector<pair<int, int>> stack = {{t, v}};

    while (!stack.empty()) {
        int currT = stack.back().first;
        int currV = stack.back().second;
        stack.pop_back();

        unionSet.insert(sets[currT].begin(), sets[currT].end());

        if (left[currT][currV] != -1) {
            stack.push_back({currT + 1, left[currT][currV]});
        }

        if (right[currT][currV] != -1) {
            stack.push_back({currT + 1, right[currT][currV]});
        }
    }

    return unionSet.size();
}

int main() {
    cin >> n >> m;

    cnt[1] = 1;
    for (int level = 1; level < n; level++) {
        cnt[level + 1] = 0;
        for (int position = 1; position <= cnt[level]; position++) {
            if ((position & (position - 1)) == 0) { // Check if position is a power of 2
                left[level][position] = cnt[level + 1] + 1;
                right[level][position] = cnt[level + 1] + 2;
                cnt[level + 1] += 2;
            } else {
                right[level][position] = cnt[level + 1] + 1;
                cnt[level + 1]++;
            }
        }
    }

    for (int i = 0; i < m; i++) {
        int op;
        cin >> op;

        if (op == 1) {
            int t, l, r, x;
            cin >> t >> l >> r >> x;
            addValue(t, l, r, x);
        } else if (op == 2) {
            int t, v;
            cin >> t >> v;
            cout << findUnion(t, v) << endl;
        }
    }

    return 0;
}