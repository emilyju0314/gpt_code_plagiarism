#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int main() {
    string w;
    cin >> w;

    // Find the length of the shortest good string in w
    int n = w.size();
    int length = 1;
    while (length < n && w[length] == w[0]) {
        length++;
    }

    // Count the number of best representations of w
    int count = 1;
    for (int i = length; i < n; i++) {
        if (w[i] != w[i % length]) {
            count = 2;
            break;
        }
    }

    cout << length << endl;
    cout << count << endl;

    return 0;
}