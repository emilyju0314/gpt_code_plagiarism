#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    int count = 0;

    for (int a = 1; a <= n; ++a) {
        for (int b = a; b <= n; ++b) {
            for (int c = b; c <= n; ++c) {
                if (a * a + b * b == c * c) {
                    count++;
                }
            }
        }
    }

    cout << count << endl;

    return 0;
}