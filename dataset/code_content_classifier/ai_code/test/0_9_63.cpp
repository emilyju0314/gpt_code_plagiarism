#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<string> sequences(n);
    for (int i = 0; i < n; i++) {
        cin >> sequences[i];
    }

    int left = 0, right = 0;
    for (int i = 0; i < n; i++) {
        int bal = 0;
        for (char c : sequences[i]) {
            if (c == '(') {
                bal++;
            } else {
                if (bal > 0) {
                    bal--;
                } else {
                    right++;
                }
            }
        }
        left += bal;
    }

    cout << min(left, right) << endl;

    return 0;
}