#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool isHappy(int d, int k, vector<int>& denominations) {
    for (int i = 0; i < (int)denominations.size(); i++) {
        if (denominations[i] % k == d || denominations[i] % k == 0) {
            return true;
        }
    }
    return false;
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> denominations(n);
    for (int i = 0; i < n; i++) {
        cin >> denominations[i];
    }

    vector<int> happyDigits;
    for (int d = 0; d < k; d++) {
        if (isHappy(d, k, denominations)) {
            happyDigits.push_back(d);
        }
    }

    cout << happyDigits.size() << endl;
    for (int i = 0; i < (int)happyDigits.size(); i++) {
        cout << happyDigits[i] << " ";
    }

    return 0;
}