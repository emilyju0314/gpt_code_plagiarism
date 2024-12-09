#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
    int n;
    cin >> n;

    unordered_map<int, int> x_count, y_count;
    unordered_map<string, int> pair_count;

    long long ans = 0;

    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;

        ans += x_count[x] + y_count[y] - pair_count[to_string(x) + "," + to_string(y)];

        x_count[x]++;
        y_count[y]++;
        pair_count[to_string(x) + "," + to_string(y)]++;
    }

    cout << ans << endl;

    return 0;
}