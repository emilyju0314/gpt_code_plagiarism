#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> chocolates(n);
    for (int i = 0; i < n; i++) {
        cin >> chocolates[i].first;
        chocolates[i].second = i + 1;
    }

    sort(chocolates.begin(), chocolates.end());

    int x = chocolates[0].second;
    int y = chocolates[1].second;
    int m = chocolates[1].first - chocolates[0].first;

    cout << x << " " << y << " " << m << endl;

    return 0;
}