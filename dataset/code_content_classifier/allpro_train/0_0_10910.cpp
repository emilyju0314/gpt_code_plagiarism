#include <iostream>
#include <vector>

using namespace std;

int main() {
    while (true) {
        int n, l, r;
        cin >> n >> l >> r;

        if (n == 0 && l == 0 && r == 0) {
            break;
        }

        vector<int> sequence(n);
        for (int i = 0; i < n; i++) {
            cin >> sequence[i];
        }

        int count = 0;
        for (int year = l; year <= r; year++) {
            int i = 1;
            for (int ai : sequence) {
                if (year % ai == 0) {
                    break;
                }
                i++;
            }

            if (i % 2 == 0 && n % 2 != 0) {
                continue;
            }
            if (i % 2 != 0 && n % 2 == 0) {
                continue;
            }

            count++;
        }

        cout << count << endl;
    }

    return 0;
}