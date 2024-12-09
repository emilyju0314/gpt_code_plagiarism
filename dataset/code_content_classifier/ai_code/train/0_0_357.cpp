#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int a, b;
        cin >> a >> b;

        int min_count = min(a, b);

        int emeralds = min_count + (a + b - 2 * min_count) / 3;

        cout << emeralds << endl;
    }

    return 0;
}