#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    long long total_rounds = 0;
    long long max_rounds = 0;

    for (int i = 0; i < n; i++) {
        long long rounds;
        cin >> rounds;
        total_rounds += rounds;
        max_rounds = max(max_rounds, rounds);
    }

    cout << max(max_rounds, (total_rounds + n - 2) / (n - 1)) << endl;

    return 0;
}