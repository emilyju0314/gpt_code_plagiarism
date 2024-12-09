#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int x1, p1, x2, p2;
        cin >> x1 >> p1 >> x2 >> p2;

        long long num1 = (long long)x1 * pow(10, p1);
        long long num2 = (long long)x2 * pow(10, p2);

        if (num1 < num2) {
            cout << "<" << endl;
        } else if (num1 > num2) {
            cout << ">" << endl;
        } else {
            cout << "=" << endl;
        }
    }

    return 0;
}