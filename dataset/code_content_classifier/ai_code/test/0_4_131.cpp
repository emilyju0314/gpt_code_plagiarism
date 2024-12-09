#include <iostream>
#include <vector>
#include <map>
#include <cmath>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> chocolates(n);
    for (int i = 0; i < n; i++) {
        cin >> chocolates[i];
    }

    int x = 0, y = 1;
    int m = 0;
    int min_exchanges = INT_MAX;

    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            int diff = abs(chocolates[i] - chocolates[j]);
            int exchanges = 0;

            while (diff > 0) {
                diff /= 2;
                exchanges++;
            }

            if (exchanges < min_exchanges) {
                min_exchanges = exchanges;
                x = i+1;
                y = j+1;
            }
        }
    }

    cout << x << " " << y << " " << min_exchanges << endl;

    return 0;
}