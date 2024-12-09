#include <iostream>
#include <iomanip>

using namespace std;

bool isProbability50OrMore(int c1, int c2, int c3) {
    int total = c1 + c2 + c3;
    int count = 0;

    for (int i = 1; i <= 10; i++) {
        if (i != c1 && i != c2 && i != c3 && total + i <= 20) {
            count++;
        }
    }

    double probability = static_cast<double>(count) / 7.0;

    return probability >= 0.5;
}

int main() {
    int c1, c2, c3;

    while (cin >> c1 >> c2 >> c3) {
        if (isProbability50OrMore(c1, c2, c3)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}