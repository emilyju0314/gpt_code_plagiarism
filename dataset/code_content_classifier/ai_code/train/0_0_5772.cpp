#include <iostream>
#include <vector>
#include <map>
#include <cmath>

using namespace std;

int main() {
    int n;
    cin >> n;

    long long total_pairs = 0;
    map<pair<long long, long long>, long long> rectCounts;

    for (int i = 0; i < n; i++) {
        long long w, h, c;
        cin >> w >> h >> c;
        rectCounts[{w, h}] = c;
        rectCounts[{h, w}] = c; // consider swapping sides as well
    }

    for (auto const &rect : rectCounts) {
        long long w = rect.first.first;
        long long h = rect.first.second;
        long long c = rect.second;

        long long num_sq = (w + 1) * (h + 1);
        total_pairs += (c * num_sq);
    }

    cout << total_pairs << endl;

    return 0;
}