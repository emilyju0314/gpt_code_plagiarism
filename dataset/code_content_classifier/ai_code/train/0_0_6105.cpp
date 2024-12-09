#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> heights(n);
    for (int i = 0; i < n; i++) {
        cin >> heights[i];
    }

    bool sorted = false;
    while (!sorted) {
        sorted = true;
        int l = -1;
        for (int i = 0; i < n - 1; i++) {
            if (heights[i] > heights[i + 1]) {
                if (l == -1) {
                    l = i;
                }
                sorted = false;
            } else {
                if (l != -1) {
                    cout << l + 1 << " " << i + 2 << endl;
                    for (int j = l; j < i; j += 2) {
                        swap(heights[j], heights[j + 1]);
                    }
                    l = -1;
                }
            }
        }
        if (l != -1) {
            cout << l + 1 << " " << n << endl;
            for (int j = l; j < n - 1; j += 2) {
                swap(heights[j], heights[j + 1]);
            }
        }
    }

    return 0;
}