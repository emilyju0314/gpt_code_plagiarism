#include <iostream>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    int count = k / 2;

    for (int i = 0; i < n; ++i) {
        if (i % 2 == 0 && count > 0) {
            cout << "1";
            count--;
        } else {
            cout << "0";
        }
    }

    return 0;
}