#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    while (cin >> n) {
        vector<string> files(n);
        int maxLength = 0;
        for (int i = 0; i < n; i++) {
            cin >> files[i];
            maxLength = max(maxLength, (int)files[i].length());
        }

        sort(files.begin(), files.end());

        int cols = (60 - maxLength) / (maxLength + 2) + 1;
        int rows = (n - 1) / cols + 1;

        for (int i = 0; i < 60; i++) {
            cout << "-";
        }
        cout << endl;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                int index = j * rows + i;
                if (index < n) {
                    cout << files[index];
                    int spaces = maxLength - files[index].length();
                    for (int k = 0; k < spaces; k++) {
                        cout << " ";
                    }
                    if (j < cols - 1) {
                        cout << "  ";
                    }
                }
            }
            cout << endl;
        }
    }

    return 0;
}