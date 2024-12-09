#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> strengths(3*N);
    for (int i = 0; i < 3*N; i++) {
        cin >> strengths[i];
    }

    sort(strengths.begin(), strengths.end());

    long long sum = 0;
    for (int i = N; i < 3*N; i += 2) {
        sum += strengths[i];
    }

    cout << sum << endl;

    return 0;
}