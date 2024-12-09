#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    if (n == 1) {
        cout << "No" << endl;
    } else {
        cout << "Yes" << endl;
        cout << "1 " << 1 << endl;
        cout << n-1;
        for (int i = 2; i <= n; i++) {
            cout << " " << i;
        }
        cout << endl;
    }

    return 0;
}