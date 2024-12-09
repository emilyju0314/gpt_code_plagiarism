#include <iostream>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    int moves = n/2 + n%2; // round(n/2) to the next integer
    if (moves % m == 0) {
        cout << moves << endl;
    } else {
        cout << -1 << endl;
    }

    return 0;
}