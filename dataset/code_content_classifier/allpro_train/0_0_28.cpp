#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int n, r, c;
    cin >> n >> r >> c;

    vector<string> words(n);
    for (int i = 0; i < n; ++i) {
        cin >> words[i];
    }

    int i = 0, j = 0, curr_len = 0;
    while (i < n) {
        if (curr_len + words[j].length() <= c) {
            curr_len += words[j].length();
            j++;
        } else {
            for (int k = i; k < j; ++k) {
                cout << words[k];
                if (k < j - 1) {
                    cout << " ";
                }
            }
            cout << endl;
            curr_len = 0;
            i = j;
        }
        if (j == n) {
            for (int k = i; k < j; ++k) {
                cout << words[k];
                if (k < j - 1) {
                    cout << " ";
                }
            }
            break;
        }
        if (j - i >= r) {
            break;
        }
    }

    return 0;
}