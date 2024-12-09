#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> shelf(n);
        for (int i = 0; i < n; i++) {
            cin >> shelf[i];
        }

        int first_book, last_book;
        for (int i = 0; i < n; i++) {
            if (shelf[i] == 1) {
                first_book = i;
                break;
            }
        }

        for (int i = n - 1; i >= 0; i--) {
            if (shelf[i] == 1) {
                last_book = i;
                break;
            }
        }

        int moves = 0;
        for (int i = first_book; i <= last_book; i++) {
            if (shelf[i] == 0) {
                moves++;
            }
        }

        cout << moves << endl;
    }

    return 0;
}