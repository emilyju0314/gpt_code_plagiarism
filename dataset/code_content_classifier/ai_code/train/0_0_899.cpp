#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n;
    vector<int> points(n);
    for (int i = 0; i < n; i++) {
        cin >> points[i];
    }

    cin >> m;
    vector<long long> distances;
    for (int i = 0; i < m; i++) {
        int type;
        cin >> type;

        if (type == 1) {
            int p, d;
            cin >> p >> d;
            points[p-1] += d;
        } else {
            int l, r;
            cin >> l >> r;
            long long sum = 0;
            for (int j = l-1; j < r; j++) {
                for (int k = j+1; k < r; k++) {
                    sum += abs(points[j] - points[k]);
                }
            }
            distances.push_back(sum);
        }
    }

    for (int i = 0; i < distances.size(); i++) {
        cout << distances[i] << endl;
    }

    return 0;
}