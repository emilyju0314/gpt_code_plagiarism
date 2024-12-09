#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

int main() {
    int N, A, B;
    cin >> N >> A >> B;

    vector<long long> items(N);
    for (int i = 0; i < N; i++) {
        cin >> items[i];
    }

    sort(items.rbegin(), items.rend());

    double max_mean = 0.0;
    long long num_ways = 0;
    for (int i = A; i <= B; i++) {
        double mean = 0.0;
        for (int j = 0; j < i; j++) {
            mean += items[j];
        }
        mean /= i;

        if (mean > max_mean) {
            max_mean = mean;
            num_ways = 1;
        } else if (mean == max_mean) {
            num_ways++;
        }
    }

    cout << fixed << setprecision(6) << max_mean << endl;
    cout << num_ways << endl;

    return 0;
}