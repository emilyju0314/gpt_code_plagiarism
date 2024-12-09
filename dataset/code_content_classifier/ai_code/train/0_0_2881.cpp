#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    long long b;
    cin >> n >> k >> b;

    vector<pair<int, int>> squares;
    for (int i = 1; i <= n; i++) {
        int cost;
        cin >> cost;
        squares.push_back({cost, i});
    }

    sort(squares.begin(), squares.end());

    long long min_square = n;
    long long sum = 0;
    for (int i = 0; i < n - k; i++) {
        sum += squares[i].first;
        if (sum > b) {
            min_square = min(min_square, static_cast<long long>(squares[i].second));
        }
    }

    cout << min_square << endl;

    return 0;
}