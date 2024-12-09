#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> jump_height(n + 1);
    vector<int> slip_distance(n + 1);
    vector<int> min_jumps(n + 1, -1);
    vector<int> jump_from(n + 1, -1);

    for (int i = 1; i <= n; i++) {
        cin >> jump_height[i];
    }

    for (int i = 1; i <= n; i++) {
        cin >> slip_distance[i];
    }

    min_jumps[0] = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = i - jump_height[i]; j < i; j++) {
            if (j >= 0 && min_jumps[j] != -1) {
                if (min_jumps[i] == -1 || min_jumps[j] + 1 < min_jumps[i]) {
                    min_jumps[i] = min_jumps[j] + 1;
                    jump_from[i] = j;
                }
            }
        }

        if (min_jumps[i] != -1) {
            i += slip_distance[i];
        }
    }

    if (min_jumps[n] == -1) {
        cout << -1 << endl;
    } else {
        vector<int> jumps;
        int cur = n;
        while (cur != 0) {
            jumps.push_back(cur);
            cur = jump_from[cur];
        }
        
        cout << jumps.size() - 1 << endl;
        for (int i = jumps.size() - 1; i >= 0; i--) {
            cout << jumps[i] << " ";
        }
        cout << endl;
    }

    return 0;
}