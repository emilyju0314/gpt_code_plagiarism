#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

class Mine {
public:
    int x, y, timer;
};

struct Comparator {
    bool operator()(const Mine& a, const Mine& b) {
        return a.timer < b.timer;
    }
};

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n, k;
        cin >> n >> k;

        vector<Mine> mines(n);
        for (int j = 0; j < n; j++) {
            cin >> mines[j].x >> mines[j].y >> mines[j].timer;
        }

        sort(mines.begin(), mines.end(), Comparator());

        int time_count = 0;
        for (int j = 0; j < n; j++) {
            int time_to_detonate = max(abs(mines[j].x), abs(mines[j].y));
            time_to_detonate = max((time_to_detonate + k - 1) / k, mines[j].timer);
            time_count = max(time_count, time_to_detonate);
        }

        cout << time_count << endl;
    }

    return 0;
}