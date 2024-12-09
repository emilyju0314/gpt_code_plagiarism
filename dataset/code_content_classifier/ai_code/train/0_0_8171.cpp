#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    cout << n << endl;

    // Print the maximum possible beauty
    cout << (1 << (n + 1)) - 2 << endl;

    // Construct a permutation with maximum beauty
    for (int i = 0; i <= n; i++) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}