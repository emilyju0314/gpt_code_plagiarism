#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> sticks(n);
    for (int i = 0; i < n; i++) {
        cin >> sticks[i];
    }

    sort(sticks.begin(), sticks.end());

    long long x = 0, y = 0;
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            x += sticks[i];
        } else {
            y += sticks[i];
        }
    }

    long long ans = x * x + y * y;
    cout << ans << endl;

    return 0;
}