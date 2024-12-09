#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    while (n--) {
        int a, b;
        cin >> a >> b;

        int operations = 0;
        while (a > 0 && b > 0) {
            if (a > b) {
                a -= b;
            } else {
                b -= a;
            }
            operations++;
        }

        cout << operations << endl;
    }

    return 0;
}