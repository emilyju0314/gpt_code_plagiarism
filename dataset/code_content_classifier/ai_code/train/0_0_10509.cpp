#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> sequence(n);
    for (int i = 0; i < n; i++) {
        cin >> sequence[i];
    }

    int changes = 0;
    for (int i = 0; i < n; i++) {
        if (sequence[i] < 0 && changes < k) {
            sequence[i] *= -1;
            changes++;
        } else {
            break;
        }
    }

    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += sequence[i];
    }

    if ((k - changes) % 2 == 1) {
        int min_element = *min_element(sequence.begin(), sequence.end());
        sum -= 2*min_element;
    }

    cout << sum << endl;

    return 0;
}