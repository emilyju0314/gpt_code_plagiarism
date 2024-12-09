#include <iostream>
#include <unordered_set>

using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    unordered_set<int> holes;
    for (int i = 0; i < m; i++) {
        int h;
        cin >> h;
        holes.insert(h);
    }

    int current_position = 1;
    for (int i = 0; i < k; i++) {
        int u, v;
        cin >> u >> v;
        if (current_position == u) {
            current_position = v;
        } else if (current_position == v) {
            current_position = u;
        }
        if (holes.count(current_position)) {
            break;
        }
    }

    cout << current_position << endl;

    return 0;
}