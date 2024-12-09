#include <iostream>
#include <vector>
#include <string>

using namespace std;

int min_operations(string a, string b) {
    int n = a.size();
    int count_a = 0, count_b = 0, diff = 0, operations = 0;

    for (int i = 0; i < n; i++) {
        count_a += a[i] - '0';
        count_b += b[i] - '0';
        if (a[i] != b[i]) {
            if (a[i] == '1') {
                diff++;
            }
            else {
                diff--;
            }
        }
    }

    if (count_a != count_b && count_a != n - count_b) {
        return -1;
    }

    for (int i = 0; i < n; i++) {
        if (a[i] == b[i]) {
            continue;
        }
        if ((count_a < count_b && a[i] == '1') || (count_a > count_b && a[i] == '0')) {
            operations++;
            diff = -diff;
        }
        count_a -= a[i] - '0';
        count_b -= b[i] - '0';
        a[i] = b[i];
    }

    if (diff != 0) {
        return -1;
    }

    return operations;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        string a, b;
        cin >> n >> a >> b;

        int result = min_operations(a, b);
        cout << result << endl;
    }

    return 0;
}