#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> s(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }

    int maxLucky = 0;

    for (int i = 0; i < n; i++) {
        int max1 = INT_MIN, max2 = INT_MIN;
        for (int j = i+1; j < n; j++) {
            if (s[j] > max1) {
                max2 = max1;
                max1 = s[j];
            } else if (s[j] > max2) {
                max2 = s[j];
            }
            maxLucky = max(maxLucky, max1 ^ max2);
        }
    }

    cout << maxLucky << endl;

    return 0;
}