#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, x;
        cin >> n >> x;

        vector<int> favorite_numbers(n);
        for (int i = 0; i < n; i++) {
            cin >> favorite_numbers[i];
        }

        int min_hops = INT_MAX;
        for (int i = 0; i < n; i++) {
            int hops = ceil((double)x / favorite_numbers[i]);
            min_hops = min(min_hops, hops + 1);
        }

        cout << min_hops << endl;
    }

    return 0;
}