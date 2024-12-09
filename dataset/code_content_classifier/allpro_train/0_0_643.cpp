#include <iostream>
#include <vector>
using namespace std;

bool isQuasibinary(int n) {
    while (n > 0) {
        int digit = n % 10;
        if (digit != 0 && digit != 1) {
            return false;
        }
        n /= 10;
    }
    return true;
}

int main() {
    int n;
    cin >> n;

    vector<int> quasibinaryNumbers;
    while (n > 0) {
        int powerOf10 = 1;
        while (!isQuasibinary(n % powerOf10)) {
            powerOf10 *= 10;
        }
        quasibinaryNumbers.push_back(n % powerOf10);
        n -= n % powerOf10;
    }

    cout << quasibinaryNumbers.size() << endl;
    for (int i = 0; i < quasibinaryNumbers.size(); i++) {
        cout << quasibinaryNumbers[i] << " ";
    }

    return 0;
}