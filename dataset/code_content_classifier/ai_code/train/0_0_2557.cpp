#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, x1, x2;
    cin >> n >> x1 >> x2;

    vector<pair<int, int>> lines(n);
    for (int i = 0; i < n; i++) {
        int k, b;
        cin >> k >> b;
        lines[i] = {k, b};
    }

    bool intersect = false;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            double x = (double)(lines[j].second - lines[i].second) / (lines[i].first - lines[j].first);
            double y = lines[i].first * x + lines[i].second;
            if (x > x1 && x < x2) {
                cout << "YES" << endl;
                return 0;
            }
        }
    }

    cout << "NO" << endl;

    return 0;
}