#include <iostream>
#include <vector>

using namespace std;

bool isDivisible(int num) {
    for (int i = 2; i < num; i++) {
        if (num % i == 0) {
            return true;
        }
    }
    return false;
}

int main() {
    int n, x;

    while (true) {
        cin >> n >> x;
        if (n == 0 && x == 0) {
            break;
        }

        vector<int> dishes(n);
        for (int i = 0; i < n; i++) {
            cin >> dishes[i];
        }

        for (int total = x - 1; total > 1; total--) {
            bool valid = true;
            for (int i = 0; i < n; i++) {
                if (total % dishes[i] == 0) {
                    valid = false;
                    break;
                }
            }

            if (valid && !isDivisible(total)) {
                cout << total << endl;
                break;
            }
        }

        if (total <= 1) {
            cout << "NA" << endl;
        }
    }

    return 0;
}