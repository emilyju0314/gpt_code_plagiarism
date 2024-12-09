#include <iostream>
#include <string>

using namespace std;

int main() {
    string a, b;
    cin >> a >> b;

    int count_ones_a = 0;
    for (char c : a) {
        if (c == '1') {
            count_ones_a++;
        }
    }

    int count_ones_b = 0;
    for (char c : b) {
        if (c == '1') {
            count_ones_b++;
        }
    }

    if ((count_ones_a % 2 == count_ones_b % 2) && (count_ones_a <= count_ones_b)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}