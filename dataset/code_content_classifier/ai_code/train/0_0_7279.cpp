#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> candies(n + 1, vector<int>());
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        candies[a].push_back(b);
    }

    vector<int> times(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            times[i] += 2 * (j - i + n) % n;
            for (int candy : candies[j]) {
                times[i] = max(times[i], 2 * (j - i + n) % n + (j != candy ? 1 : 0));
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << times[i] << " ";
    }

    return 0;
}