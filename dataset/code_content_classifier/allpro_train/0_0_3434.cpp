#include <iostream>

using namespace std;

bool isTriangle(int a, int b, int c) {
    return a + b > c && b + c > a && a + c > b;
}

int main() {
    int n;
    cin >> n;

    int count = 0;
    for (int a = 1; a <= n; a++) {
        for (int b = a; b <= n; b++) {
            for (int c = b; c <= n; c++) {
                if ((a^b^c) == 0 && isTriangle(a, b, c)) {
                    count++;
                }
            }
        }
    }

    cout << count << endl;

    return 0;
}