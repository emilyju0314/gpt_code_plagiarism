#include <iostream>

using namespace std;

int main() {
    int n, a, b;
    cin >> n >> a >> b;

    int x = min(a / n, b / (n-1));
    for (int i = x; i >= 0; i--) {
        if (a / i + b / (n-i) >= n) {
            x = i;
            break;
        }
    }

    cout << x << endl;

    return 0;
}