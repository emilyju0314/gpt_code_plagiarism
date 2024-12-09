#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> upper(N), middle(N), lower(N);

    for (int i = 0; i < N; i++) {
        cin >> upper[i];
    }

    for (int i = 0; i < N; i++) {
        cin >> middle[i];
    }

    for (int i = 0; i < N; i++) {
        cin >> lower[i];
    }

    sort(upper.begin(), upper.end());
    sort(middle.begin(), middle.end());
    sort(lower.begin(), lower.end());

    long long count = 0;

    for (int i = 0; i < N; i++) {
        int upper_count = upper.end() - upper.begin();
        int lower_count = lower.end() - lower.begin();

        int middle_count = middle.end() - upper.end();
        if (middle_count > 0) {
            count += (long long)upper_count * lower_count;
        }
    }

    cout << count << endl;

    return 0;
}