#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> balls(n);
    for(int i = 0; i < n; i++) {
        cin >> balls[i];
    }

    sort(balls.rbegin(), balls.rend());

    long long penalty = 0;
    for(int i = 1; i < n; i++) {
        penalty += (long long) balls[i] * (i - 1);
    }

    cout << penalty << endl;

    return 0;
}