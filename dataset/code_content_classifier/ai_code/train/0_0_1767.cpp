#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> diary(n);
    for (int i = 0; i < n; i++) {
        cin >> diary[i];
    }

    int booksRead = 0;
    int lastBookRead = 0;

    for (int i = 0; i < n; i++) {
        if (diary[i] != 0) {
            if (lastBookRead == 0) {
                for (int j = i; j >= 0 && diary[j] == 0; j--) {
                    diary[j] = diary[i];
                }
            }
            lastBookRead = diary[i];
        } else {
            if (lastBookRead == 0) {
                diary[i] = 1;
                lastBookRead = 1;
            } else if (lastBookRead < 5) {
                diary[i] = lastBookRead;
            } else {
                cout << -1 << endl;
                return 0;
            }
        }
        booksRead = max(booksRead, lastBookRead);
    }

    cout << booksRead << endl;
    for (int i = 0; i < n; i++) {
        cout << diary[i] << " ";
    }

    return 0;
}