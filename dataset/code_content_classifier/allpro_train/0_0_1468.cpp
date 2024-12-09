#include <iostream>
#include <vector>

using namespace std;

bool hasDivisors(int n) {
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return true;
        }
    }
    return false;
}

int main() {
    int n;
    cin >> n;

    int start = 1;
    while (true) {
        if (!hasDivisors(start) && !hasDivisors(start + 1) && !hasDivisors(start + 2) && n > 0) {
            cout << start << endl;
            for (int i = 2; i <= n + 1; i++) {
                cout << start + (i - 2) << endl;
            }
            break;
        }
        start++;
    }

    return 0;
}