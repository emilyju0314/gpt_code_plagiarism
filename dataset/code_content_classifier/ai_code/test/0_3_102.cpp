#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int t;
    cin >> t;

    // process each test case
    for (int i = 0; i < t; i++) {
        int n, m;
        cin >> n >> m;

        string s;
        cin >> s;

        int left = 0, right = 0, up = 0, down = 0;

        // count the number of L, R, U, D commands in the sequence
        for (char c : s) {
            if (c == 'L') left++;
            else if (c == 'R') right++;
            else if (c == 'U') up++;
            else if (c == 'D') down++;
        }

        // decide the starting cell based on the counts
        int startRow = 1, startCol = 1;
        if (left >= right) startCol = 1 + left - right;
        else startCol = m - right + left + 1;
        if (up >= down) startRow = 1 + up - down;
        else startRow = n - down + up + 1;

        cout << startRow << " " << startCol << endl;
    }

    return 0;
}