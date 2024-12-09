#include <iostream>
#include <vector>
using namespace std;

bool isLucky(int n) {
    while (n > 0) {
        int digit = n % 10;
        if (digit != 4 && digit != 7) {
            return false;
        }
        n /= 10;
    }
    return true;
}

int main() {
    int n;
    cin >> n;

    vector<int> luckyNumbers;
    for (int i = 1; i <= 1000; i++) {
        if (isLucky(i)) {
            luckyNumbers.push_back(i);
        }
    }

    for (int i = 0; i < luckyNumbers.size(); i++) {
        if (luckyNumbers[i] == n) {
            cout << i + 1 << endl;
            break;
        }
    }

    return 0;
}