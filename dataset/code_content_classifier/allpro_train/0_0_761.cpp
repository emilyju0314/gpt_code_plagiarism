#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, x;
    cin >> N >> x;

    vector<int> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }

    long long min_time = 0;
    for (int i = 0; i < N - 1; i++) {
        min_time += a[i];
    }

    sort(a.begin(), a.end());

    if (min_time > a[N - 1]) {
        min_time += x;
    }

    cout << min_time << endl;

    return 0;
}