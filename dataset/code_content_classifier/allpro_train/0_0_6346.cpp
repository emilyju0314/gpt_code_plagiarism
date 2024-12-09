#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    long long b;
    cin >> n >> k >> b;

    vector<int> squares(n);
    for (int i = 0; i < n; i++) {
        cin >> squares[i];
    }

    int min_square = n;
    long long total_cost = 0;

    for (int i = 0; i < k; i++) {
        total_cost += squares[i];
        if (total_cost <= b && min_square > i+1) {
            min_square = i+1;
        }
    }

    cout << min_square << endl;

    return 0;
}