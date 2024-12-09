#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end(), greater<int>());

    int sum = 0;
    for (int i = 0; i < N-1; i++) {
        sum += a[i];
    }

    if (a[N-1] <= sum && (sum % 2 == 0 || sum >= 2 * a[N-1])) {
        cout << "Possible" << endl;
    } else {
        cout << "Impossible" << endl;
    }

    return 0;
}