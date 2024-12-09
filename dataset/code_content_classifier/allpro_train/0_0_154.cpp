#include <iostream>
using namespace std;

int main() {
    int y1, m1, d1;
    int y2, m2, d2;

    cin >> y1 >> m1 >> d1;
    cin >> y2 >> m2 >> d2;

    int age1 = y1 * 10000 + m1 * 100 + d1;
    int age2 = y2 * 10000 + m2 * 100 + d2;

    int max_age_diff = max(abs(y1 - y2), abs(m1 - m2) * 12 + abs(d1 - d2) + 1);
    if (y1 < y2) {
        if (m1 < m2 || (m1 == m2 && d1 < d2)) {
            max_age_diff--;
        }
    } else if (y1 > y2) {
        if (m1 > m2 || (m1 == m2 && d1 > d2)) {
            max_age_diff--;
        }
    }

    cout << max_age_diff << endl;

    return 0;
}