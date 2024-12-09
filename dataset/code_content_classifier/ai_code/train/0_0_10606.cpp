#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

int main() {
    int n, l;
    cin >> n >> l;

    vector<int> lanterns(n);
    for (int i = 0; i < n; i++) {
        cin >> lanterns[i];
    }

    sort(lanterns.begin(), lanterns.end());

    double max_distance = 0;
    for (int i = 0; i < n - 1; i++) {
        max_distance = max(max_distance, lanterns[i + 1] - lanterns[i]);
    }

    double result = max(max(lanterns[0], l - lanterns[n - 1]), max_distance / 2.0);
    cout << fixed << setprecision(10) << result << endl;

    return 0;
}