#include <iostream>
#include <vector>
using namespace std;

bool check(int num, int p) {
    int res = 0;
    while (num > 0) {
        int digit = num % 10;
        res = (res * 10 + digit) % p;
        num /= 10;
    }
    return res == 0;
}

int main() {
    int n, p;
    cin >> n >> p;

    vector<int> elements;
    for (int i = 1; i <= n; i++) {
        elements.push_back(i);
    }

    bool found = false;
    for (int i = 0; i < (1 << n); i++) {
        vector<int> subset;
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) {
                subset.push_back(elements[j]);
            }
        }

        int xor_result = 0;
        int count = 0;
        for (int num : subset) {
            xor_result ^= num;
            count = count * 10 + num;
        }

        if (xor_result == 0 && count % p == 0) {
            cout << "Yes" << endl;
            cout << subset.size() << endl;
            for (int num : subset) {
                cout << num << " ";
            }
            cout << endl;
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "No" << endl;
    }

    return 0;
}