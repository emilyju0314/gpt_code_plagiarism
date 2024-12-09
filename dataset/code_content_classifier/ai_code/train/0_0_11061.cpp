#include <iostream>

using namespace std;

int main() {
    int T1, T2;
    long long A1, A2, B1, B2;
    cin >> T1 >> T2 >> A1 >> A2 >> B1 >> B2;

    long long diff1 = (A1 - B1) * T1;
    long long diff2 = (A1 - B2) * T2;
    
    if (diff1 * diff2 >= 0) {
        cout << 0 << endl;
        return 0;
    }

    if (diff1 + diff2 < 0) {
        swap(A1, B1);
        swap(A2, B2);
        diff1 = -diff1;
        diff2 = -diff2;
    }

    long long diff = abs(diff1) + abs(diff2);
    long long cycle = abs(diff1) / diff;

    if (abs(diff1) % diff == 0) {
        cout << "infinity" << endl;
    } else {
        cout << 2 * cycle + 1 << endl;
    }

    return 0;
}