#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<string> sequences(n);
    int total_open = 0;
    int total_close = 0;

    for (int i = 0; i < n; i++) {
        cin >> sequences[i];
        for(char c : sequences[i]) {
            if (c == '(') total_open++;
            else total_close++;
        }
    }

    int min_diff = min(total_open, total_close);
    int open = 0;
    int close = 0;
    for (int i = 0; i < n; i++) {
        for (char c : sequences[i]) {
            if (c == '(') open++;
            else close++;

            if (open - close == min_diff) {
                cout << open << endl;
                return 0;
            }
        }

        min_diff = min(min_diff, open - close);
    }

    cout << min_diff << endl;

    return 0;
}