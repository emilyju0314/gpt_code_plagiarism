#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> sequence(n);
    for (int i = 0; i < n; i++) {
        cin >> sequence[i];
    }

    bool bitLGMWins = false;
    int xorSum = 0;
    for (int num : sequence) {
        xorSum ^= num;
    }

    int zerosCount = 0;
    for (int num : sequence) {
        zerosCount += (num == xorSum);
    }

    if ((n % 2 == 0 && zerosCount == n) || (n % 2 != 0 && zerosCount != n)) {
        bitLGMWins = true;
    }

    if (bitLGMWins) {
        cout << "BitLGM" << endl;
    } else {
        cout << "BitAryo" << endl;
    }

    return 0;
}