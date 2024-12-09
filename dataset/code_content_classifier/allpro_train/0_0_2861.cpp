#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int x;
    cin >> x;

    vector<int> operationsA;
    int count = 0;

    while (x % 2 == 0) {
        x /= 2;
        count++;
    }

    while (x > 1) {
        int power = log2(x + 1);
        x = x ^ ((1 << power) - 1);
        operationsA.push_back(power);
        x++;
        count++;
    }

    cout << count << endl;

    for (int i = 0; i < operationsA.size(); i++) {
        cout << operationsA[i] << " ";
    }

    cout << endl;

    return 0;
}