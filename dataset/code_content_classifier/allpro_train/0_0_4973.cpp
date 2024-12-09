#include <iostream>
#include <string>

using namespace std;

int main() {
    int n, p;
    cin >> n >> p;

    string s;
    cin >> s;

    p--; // adjust 1-based indexing to 0-based indexing

    int mid = n / 2;
    int moves = 0;

    if (p >= mid) {
        p = n - p - 1;
    }

    for (int i = 0; i < mid; i++) {
        int diff = abs(s[i] - s[n - i - 1]);
        moves += min(diff, 26 - diff);
    }

    moves += abs(p - mid);

    cout << moves << endl;

    return 0;
}