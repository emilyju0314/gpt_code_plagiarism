#include <iostream>
#include <algorithm>

using namespace std;

int gcd(int a, int b) {
    while (b != 0) {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}

int main() {
    int a, b, n;
    cin >> a >> b;
    cin >> n;

    int g = gcd(a, b);

    for (int i = 0; i < n; i++) {
        int low, high;
        cin >> low >> high;

        int result = -1;

        for (int j = high; j >= low; j--) {
            if (g % j == 0) {
                result = j;
                break;
            }
        }

        cout << result << endl;
    }

    return 0;
}