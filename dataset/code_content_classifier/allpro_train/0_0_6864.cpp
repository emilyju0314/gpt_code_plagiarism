#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> figures(n);
    for (int i = 0; i < n; i++) {
        cin >> figures[i].first >> figures[i].second;
    }

    int t;
    cin >> t;

    vector<long long> p(t);
    for (int i = 0; i < t; i++) {
        cin >> p[i];
    }

    long long factor = 1;
    long long points = 0;
    int idx = 0;
    for (int i = 0; i < n; i++) {
        while (figures[i].first > 0) {
            points += factor * figures[i].second;
            figures[i].first--;

            if (idx < t && figures[i].first == p[idx]) {
                factor++;
                idx++;
            }
        }
    }

    cout << points << endl;

    return 0;
}