#include <iostream>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    int teams = 0;
    while (n > 0 && m > 0) {
        if (n > m) {
            n -= 2;
            m--;
        } else {
            m -= 2;
            n--;
        }
        teams++;
    }

    cout << teams << endl;

    return 0;
}