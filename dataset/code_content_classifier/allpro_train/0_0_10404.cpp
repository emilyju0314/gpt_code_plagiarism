#include <iostream>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    int totalCandiesAte = min(k - 1, n - 1);

    int remainingActions = n - totalCandiesAte;

    cout << totalCandiesAte + remainingActions / 2 << endl;

    return 0;
}