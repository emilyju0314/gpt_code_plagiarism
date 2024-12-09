#include <iostream>
#include <vector>

using namespace std;

int main() {
    long long n, q, k, d;
    cin >> n >> q >> k >> d;

    if (n % 2 != 0) {
        cout << -1 << endl;
        return 0;
    }

    vector<string> operations;
    while (q > 0 && k != d) {
        if (k % 2 == 0) {
            operations.push_back("0");
            k = (k + 1) / 2;
        } else {
            operations.push_back("1");
            k = (k + n + 1) / 2;
        }
        q--;
    }

    if (q > 0) {
        cout << -1 << endl;
    } else {
        for (string op : operations) {
            cout << op << endl;
        }
    }

    return 0;
}