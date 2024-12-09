#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        int c = n / 4;
        cout << c << " " << 2*c << " " << c << "\n";
    }

    return 0;
}