#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> perm(n);
    for (int i = 0; i < n; i++) {
        cin >> perm[i];
    }

    vector<int> rev(n);
    for (int i = 0; i < n; i++) {
        cin >> rev[i];
    }

    vector<bool> visited(n, false);
    int changes = 0;

    map<pair<int, int>, int> count; // count[i][j] represents the number of elements that appear on index i for jth time
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            visited[i] = true;
            int cur = perm[i] - 1;
            int cur_rev = rev[i];
            int cycle_length = 1;

            // Finding the cycle length
            while (cur != i) {
                visited[cur] = true;
                cur = perm[cur] - 1;
                cur_rev ^= rev[cur];
                cycle_length++;
            }

            // Update count with cycle length
            count[{cur_rev, cycle_length}]++;
        }
    }

    for (auto& it : count) {
        int k = it.first.second;
        int even = it.second;
        int odd = 0;

        if (it.first.first == 1) {
            odd = it.second;
            even = 0;
        }

        changes += ((k - max(odd, even)) % 2);
    }

    cout << changes << endl;

    return 0;
}