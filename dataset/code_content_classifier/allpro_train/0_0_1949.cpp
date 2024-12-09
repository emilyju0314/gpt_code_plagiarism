#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> weights(n);
    for (int i = 0; i < n; i++) {
        cin >> weights[i];
    }

    vector<int> count(30, 0);
    for (int w : weights) {
        count[__builtin_ctz(w)]++;
    }

    int steps = 0;
    for (int c : count) {
        steps = max(steps, c);
    }

    cout << steps << endl;

    return 0;
}