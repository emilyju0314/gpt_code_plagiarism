#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n, k;
        cin >> n >> k;

        vector<int> a(n);
        for (int j = 0; j < n; j++) {
            cin >> a[j];
        }

        sort(a.begin(), a.end());

        int score = 0;
        int index = n-1;

        for (int j = 0; j < k; j++) {
            score += a[index-1] / a[index];
            index -= 2;
        }

        int remaining_sum = 0;
        for (int j = index; j >= 0; j--) {
            remaining_sum += a[j];
        }

        cout << score + remaining_sum << endl;
    }

    return 0;
}