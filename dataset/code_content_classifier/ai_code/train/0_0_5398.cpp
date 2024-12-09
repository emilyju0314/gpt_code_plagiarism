#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    // The worst-case scenario is when Manao has to try all possible combinations of buttons
    // before he can successfully open the lock
    int result = 1; // Manao always needs to at least push one button
    for (int i = 2; i <= n; i++) {
        result += i * (i - 1); // Each time Manao pushes a button, he eliminates i - 1 possibilities
    }

    cout << result << endl;

    return 0;
}