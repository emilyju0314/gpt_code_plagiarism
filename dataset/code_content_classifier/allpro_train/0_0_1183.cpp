#include <iostream>

using namespace std;

int main() {
    int k, a, b;
    cin >> k >> a >> b;

    if (a < k && b < k) {
        cout << -1 << endl;
    } else {
        int totalPoints = a + b;
        cout << totalPoints / k << endl;
    }

    return 0;
}