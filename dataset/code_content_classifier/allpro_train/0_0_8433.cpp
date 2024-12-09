#include <iostream>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    int min_candies = n / m;
    int extra_candies = n % m;

    for (int i = 0; i < m; i++) {
        if (extra_candies > 0) {
            cout << min_candies + 1 << " ";
            extra_candies--;
        } else {
            cout << min_candies << " ";
        }
    }

    return 0;
}