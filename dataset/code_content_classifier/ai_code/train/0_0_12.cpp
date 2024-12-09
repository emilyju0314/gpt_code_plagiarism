#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> x(n);
    vector<int> v(n);

    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    long long sum = 0;
    long long total_sum = 0;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (v[i] > v[j]) {
                sum = (long long)(x[j] - x[i]) * (v[i] - v[j]);
                total_sum += sum;
            }
        }
    }

    cout << total_sum;

    return 0;
}