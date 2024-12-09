#include <iostream>
#include <vector>

using namespace std;

int main() {
    long long n, k, p;
    cin >> n >> k >> p;

    if (k == n) {
        for (int i = 0; i < p; i++) {
            cout << "X";
        }
    } else {
        vector<long long> positions;
        for (int i = 0; i < p; i++) {
            long long xi;
            cin >> xi;
            positions.push_back(xi);
        }

        vector<char> result;
        for (long long xi : positions) {
            if ((xi > k) || ((k == n) && ((xi % n) == 0))) {
                result.push_back('.');
            } else {
                result.push_back('X');
            }
        }

        for (char c : result) {
            cout << c;
        }
    }

    return 0;
}