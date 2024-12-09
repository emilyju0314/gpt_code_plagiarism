#include <iostream>

using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        int n, x;
        cin >> n >> x;

        // Formula to calculate the x-th remaining number
        int remain = 2 * x;
        cout << remain << endl;
    }

    return 0;
}