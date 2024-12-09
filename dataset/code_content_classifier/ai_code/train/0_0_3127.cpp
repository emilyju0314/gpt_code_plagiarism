#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int q;
    cin >> q;

    for (int i = 0; i < q; i++) {
        int n;
        cin >> n;

        vector<int> goods(n);
        int total = 0;

        for (int j = 0; j < n; j++) {
            cin >> goods[j];
            total += goods[j];
        }

        int minPrice = (total + n - 1) / n; // Calculate the minimum possible equal price

        cout << minPrice << endl;
    }

    return 0;
}