#include <iostream>
#include <vector>

using namespace std;

bool isFibonacci(int n) {
    int a = 1, b = 1;
    while (b <= n) {
        if (b == n) {
            return true;
        }
        int temp = b;
        b = a + b;
        a = temp;
    }
    return false;
}

int main() {
    int n;
    cin >> n;

    vector<char> name(n);
    for (int i = 0; i < n; i++) {
        if (isFibonacci(i + 1)) {
            name[i] = 'O';
        } else {
            name[i] = 'o';
        }
    }

    for (int i = 0; i < n; i++) {
        cout << name[i];
    }
    cout << endl;

    return 0;
}