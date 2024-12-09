#include <iostream>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    int clicks = 0;
    while (n != m) {
        if (n < m || n % 2 != m % 2) {
            n++;
        } else {
            n /= 2;
        }
        clicks++;
    }

    cout << clicks << endl;

    return 0;
}