#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<pair<int, int>> points(N);
    for (int i = 0; i < N; i++) {
        cin >> points[i].first >> points[i].second;
    }

    int m = 1;
    while (m < 41) {
        for (long long d1 = 1; d1 <= 1e12; d1++) {
            for (long long d2 = 1; d2 <= 1e12; d2++) {
                // Calculate coordinates of Joint m
                int x = 0, y = 0;
                string way;
                for (int i = 0; i < m; i++) {
                    if (points[0].first > x) {
                        x += d1;
                        way += "R";
                    } else if (points[0].first < x) {
                        x -= d1;
                        way += "L";
                    } else if (points[0].second > y) {
                        y += d2;
                        way += "U";
                    } else if (points[0].second < y) {
                        y -= d2;
                        way += "D";
                    }
                }

                bool valid = true;
                for (int i = 1; i < N; i++) {
                    int xi = 0, yi = 0;
                    for (int j = 0; j < m; j++) {
                        if (way[j] == 'R') xi += d1;
                        else if (way[j] == 'L') xi -= d1;
                        else if (way[j] == 'U') yi += d2;
                        else yi -= d2;
                    }
                    if (xi != points[i].first || yi != points[i].second) {
                        valid = false;
                        break;
                    }
                }

                if (valid) {
                    cout << m << endl;
                    cout << d1 << " " << d2 << endl;
                    cout << way << endl;
                    return 0;
                }
            }
        }
        m++;
    }

    cout << -1 << endl;

    return 0;
}