#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, x;
        cin >> n >> x;

        int odd_count = 0;
        int even_count = 0;

        for (int i = 0; i < n; i++) {
            int num;
            cin >> num;
            if (num % 2 == 0) {
                even_count++;
            } else {
                odd_count++;
            }
        }

        if (odd_count == 0 || (even_count == 0 && x % 2 == 0) || (odd_count >= x)) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }

    return 0;
}