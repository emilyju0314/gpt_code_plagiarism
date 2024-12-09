#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool is_palindrome(string s) {
    return s == string(s.rbegin(), s.rend());
}

int main() {
    int H, W;
    cin >> H >> W;

    vector<string> matrix(H);
    for (int i = 0; i < H; i++) {
        cin >> matrix[i];
    }

    vector<int> count(26, 0);
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            count[matrix[i][j] - 'a']++;
        }
    }

    int odd_count = 0;
    for (int i = 0; i < 26; i++) {
        if (count[i] % 2 != 0) {
            odd_count++;
        }
    }

    if (odd_count > (H + W) % 2) {
        cout << "No" << endl;
    } else {
        cout << "Yes" << endl;
    }

    return 0;
}