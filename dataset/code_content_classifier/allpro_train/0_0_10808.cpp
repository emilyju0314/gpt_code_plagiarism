#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> a(3*N);
    for (int i = 0; i < 3*N; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    long long int score = 0;
    for (int i = N; i < 2*N; i++) {
        score += a[i];
    }
    for (int i = N-1; i >= 0; i--) {
        score -= a[i];
    }

    cout << score << endl;

    return 0;
}