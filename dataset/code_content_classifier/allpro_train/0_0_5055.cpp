#include <iostream>
#include <vector>
#include <set>

const int MAX_N = 7000;
int cnt[MAX_N + 1];
int left[MAX_N + 1][MAX_N];
int right[MAX_N + 1][MAX_N];
std::set<int> A[MAX_N + 1][MAX_N];

void addValue(int t, int l, int r, int x) {
    for (int i = l-1; i < r; i++) {
        A[t][i].insert(x);
    }
}

int findSubtreeUnion(int t, int v) {
    std::set<int> result;
    std::vector<std::pair<int, int>> stack;
    stack.push_back({t, v});

    while (!stack.empty()) {
        int level = stack.back().first;
        int position = stack.back().second;
        stack.pop_back();

        if (position != -1) {
            for (int val : A[level][position]) {
                result.insert(val);
            }
            if (left[level][position] != -1) {
                stack.push_back({level + 1, left[level][position]});
            }
            if (right[level][position] != -1) {
                stack.push_back({level + 1, right[level][position]});
            }
        }
    }

    return result.size();
}

int main() {
    int n, m;
    std::cin >> n >> m;

    cnt[1] = 1;
    for (int i = 0; i <= MAX_N; i++) {
        for (int j = 0; j < MAX_N; j++) {
            left[i][j] = -1;
            right[i][j] = -1;
        }
    }

    for (int level = 1; level < n; level++) {
        cnt[level + 1] = 0;
        for (int position = 1; position <= cnt[level]; position++) {
            if ((position & (position - 1)) == 0) {
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
        int type;
        std::cin >> type;

        if (type == 1) {
            int t, l, r, x;
            std::cin >> t >> l >> r >> x;
            addValue(t, l, r, x);
        } else if (type == 2) {
            int t, v;
            std::cin >> t >> v;
            int result = findSubtreeUnion(t, v-1);
            std::cout << result << std::endl;
        }
    }

    return 0;
}