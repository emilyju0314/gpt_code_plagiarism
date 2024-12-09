#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    int n, c;
    cin >> n >> c;

    vector<int> a(n);
    unordered_map<int, int> freq;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        freq[a[i]]++;
    }

    int result = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            int sum = 0, count = 0;
            for (int k = i; k <= j; k++) {
                if (a[k] == c) count++;
                sum += a[k];
            }

            int k = (c * (j - i + 1) - sum) / (j - i + 1);
            if ((c * (j - i + 1) - sum) % (j - i + 1) == 0 && freq[k] > count) {
                result = max(result, count + freq[k]);
            }
        }
    }

    cout << result << endl;

    return 0;
}