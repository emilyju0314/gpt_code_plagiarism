#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    string s;
    cin >> s;
    int k;
    cin >> k;

    int n = s.size();
    for (int i = 0; i < n; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n && j - i <= k; j++) {
            if (s[j] < s[min_idx]) {
                min_idx = j;
            }
        }
        for (int j = min_idx; j > i; j--) {
            swap(s[j], s[j - 1]);
            k -= (j - i);
        }
        if (k <= 0) {
            break;
        }
    }

    cout << s << endl;

    return 0;
}