#include <iostream>

using namespace std;

int countLoops(int num) {
    string str = to_string(num);
    int loops = 0;
    for (char c : str) {
        if (c == '0' || c == '6' || c == '9') loops++;
        else if (c == '8') loops += 2;
    }
    return loops;
}

int main() {
    int k;
    cin >> k;

    for (int i = 1; i <= 1018; i++) {
        if (countLoops(i) == k) {
            cout << i << endl;
            return 0;
        }
    }

    cout << -1 << endl;

    return 0;
}