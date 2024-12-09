#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, q;
    cin >> n >> q;

    string description;
    cin >> description;

    vector<int> depth(2 * n, 0);
    int current_depth = 0;
    int max_depth = 0;
    vector<int> max_start(2 * n, 0);

    for (int i = 0; i < 2 * n; i++) {
        if (description[i] == '(') {
            current_depth++;
        } else {
            current_depth--;
        }
        depth[i] = current_depth;
        max_depth = max(max_depth, current_depth);
        if (max_depth == current_depth) {
            max_start[max_depth] = i;
        }
    }

    for (int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;

        swap(description[a], description[b]);

        int start = min(a, b);
        int end = max(a, b);

        max_depth = depth[max_start[end]] - depth[start];
        if (end - start > 1) {
            max_depth = max(max_depth, depth[start] + depth[end] - 2 * depth[start]);
        }

        cout << max_depth + 1 << endl;
    }

    cout << max_depth + 1 << endl;

    return 0;
}