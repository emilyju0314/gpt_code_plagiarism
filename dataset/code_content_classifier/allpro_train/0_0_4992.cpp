#include <iostream>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    int totalChips = 0;
    int currentWalrus = 1;

    for (int i = 1; i <= m; i++) {
        if (i > totalChips) {
            break;
        }

        totalChips -= i;
        currentWalrus = (currentWalrus % n) + 1;
    }

    cout << totalChips << endl;

    return 0;
}