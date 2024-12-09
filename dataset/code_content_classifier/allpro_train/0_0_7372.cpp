#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, a, b, k;
    cin >> n >> a >> b >> k;

    vector<int> h(n);
    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }

    vector<int> damage(n);
    int max_points = 0;

    for (int i = 0; i < n; i++) {
        int remain = h[i] % (a + b);
        damage[i] = (remain == 0) ? b : (remain > a) ? remain - a : 0;
    }

    sort(damage.begin(), damage.end());

    for (int i = 0; i < n; i++) {
        if (damage[i] == 0) {
            max_points++;
        } else if (k > 0) {
            k--;
        } else {
            break;
        }
    }

    cout << max_points << endl;

    return 0;
}