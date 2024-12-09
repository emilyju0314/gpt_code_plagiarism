#include <iostream>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    int moves = 2 + (n-1) + (n-1) + min(k-1, n-k) + (n-1);

    cout << moves << endl;

    return 0;
}