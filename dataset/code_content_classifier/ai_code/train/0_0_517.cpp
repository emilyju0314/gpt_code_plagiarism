#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    if (n == 2) {
        cout << 0 << endl;
    } else {
        long long score = 4 * (n - 1);
        cout << score << endl;
    }

    return 0;
}