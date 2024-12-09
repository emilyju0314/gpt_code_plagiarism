#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;

    vector<pair<long long, int>> pairs(t);
    for (int i = 0; i < t; i++) {
        cin >> pairs[i].first >> pairs[i].second;
    }

    for (int i = 0; i < t; i++) {
        long long p = pairs[i].first;
        int q = pairs[i].second;
        long long x = p;
        while (p % x == 0 && x % q == 0) {
            x--;
        }
        cout << x << endl;
    }

    return 0;
}