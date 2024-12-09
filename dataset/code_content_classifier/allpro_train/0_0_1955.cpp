#include <iostream>
#include <vector>

using namespace std;

int main() {
    int a, b;
    cin >> a >> b;

    vector<int> operations;
    operations.push_back(b);

    while (b > a) {
        if (b % 10 == 1) {
            b /= 10;
            operations.push_back(b);
        } else if (b % 2 == 0) {
            b /= 2;
            operations.push_back(b);
        } else {
            break;
        }
    }

    if (b == a) {
        cout << "YES\n";
        cout << operations.size() << endl;
        for (int i = operations.size() - 1; i >= 0; i--) {
            cout << operations[i] << " ";
        }
    } else {
        cout << "NO";
    }

    return 0;
}