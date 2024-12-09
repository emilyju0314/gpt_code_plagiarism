#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

const int MOD = 1e9 + 7;

int countSetBits(int n) {
    int count = 0;
    while (n > 0) {
        count += n & 1;
        n >>= 1;
    }
    return count;
}

int main() {
    string n;
    int k;
    cin >> n >> k;

    int num = stoi(n, nullptr, 2);
    int specialCount = 0;

    for (int i = 1; i <= num; i++) {
        int curr = i;
        int operations = 0;

        while (curr != 1) {
            curr = countSetBits(curr);
            operations++;

            if (operations > k) {
                break;
            }
        }

        if (curr == 1 && operations == k) {
            specialCount = (specialCount + 1) % MOD;
        }
    }

    cout << specialCount << endl;

    return 0;
}