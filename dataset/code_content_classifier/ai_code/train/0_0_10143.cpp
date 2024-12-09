#include <iostream>
#include <vector>

using namespace std;

bool is_vowel(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

int main() {
    int k;
    cin >> k;

    vector<char> vowels = {'a', 'e', 'i', 'o', 'u'};

    int n = -1, m = -1;
    for (int i = 5; i * i <= k; ++i) {
        if (k % i == 0) {
            n = i;
            m = k / i;
            break;
        }
    }

    if (n == -1) {
        cout << -1 << endl;
    } else {
        vector<vector<char>> grid(n, vector<char>(m));

        int vowel_index = 0;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                grid[i][j] = vowels[vowel_index];
                vowel_index = (vowel_index + 1) % 5;
            }
        }

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cout << grid[i][j];
            }
        }
        cout << endl;
    }

    return 0;
}