#include <iostream>
#include <set>
#include <cmath>

using namespace std;

int main() {
    int n;
    cin >> n;

    set<int> fun_values;

    for (int k = 1; k <= sqrt(n); k++) {
        if (n % k == 0) {
            fun_values.insert(k * (n + 1) / 2);
            if (k != n / k) {
                fun_values.insert((n / k) * (n + 1) / 2);
            }
        }
    }

    for (int fun_value : fun_values) {
        cout << fun_value << " ";
    }

    return 0;
}