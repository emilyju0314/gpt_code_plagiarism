#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int k, q;
    cin >> k >> q;

    for (int i = 0; i < q; i++) {
        int pi;
        cin >> pi;

        int days = ceil(log(1 - (1 - 1.0 / k) * pi) / log(1 - 1.0 / k));
        cout << days << endl;
    }

    return 0;
}