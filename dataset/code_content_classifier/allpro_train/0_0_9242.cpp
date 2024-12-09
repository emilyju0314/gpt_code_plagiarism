#include <iostream>
using namespace std;

int main() {
    long long N;
    cin >> N;

    if (N < 4) {
        cout << 1 << endl;
    } else if (N == 4) {
        cout << 7 << endl;
    } else if (N % 2 == 0) {
        cout << "inf" << endl;
    } else {
        cout << 1 << endl;
    }

    return 0;
}