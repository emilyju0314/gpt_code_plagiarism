#include <iostream>
using namespace std;

int main() {
    long long n, k;
    cin >> n >> k;

    long long total_pipes = 1; // Initially only 1 pipe with flowing water

    int splitters = 0;
    while (total_pipes < n) {
        splitters++;
        total_pipes += k - 1; // Each splitter adds (x - 1) pipes where x is the number of outputs
    }

    if (total_pipes == n) {
        cout << splitters << endl;
    } else {
        cout << -1 << endl;
    }

    return 0;
}