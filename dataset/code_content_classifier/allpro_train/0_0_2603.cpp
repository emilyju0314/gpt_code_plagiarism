#include <iostream>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    int maxChessmen = (n / 3) * (m / 3) * 2;

    if (n % 3 == 2) {
        maxChessmen += m / 3;
    } else if (n % 3 == 1) {
        maxChessmen += (m / 3) * 2;
    }

    if (m % 3 == 2) {
        maxChessmen += n / 3;
    } else if (m % 3 == 1) {
        maxChessmen += (n / 3) * 2;
    }

    cout << maxChessmen << endl;

    return 0;
}