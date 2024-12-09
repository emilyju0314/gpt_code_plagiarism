#include <iostream>

using namespace std;

int main() {
    int A, B;

    while (cin >> A >> B) {
        if (A == 0 && B == 0) {
            break;
        }

        int change = B - A;
        int num_1000 = change / 1000;
        int num_500 = (change % 1000) / 500;
        int num_100 = ((change % 1000) % 500) / 100;

        cout << num_100 << " " << num_500 << " " << num_1000 << endl;
    }

    return 0;
}