#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, k, m;
    while (cin >> n >> k >> m && (n || k || m)) {
        vector<bool> eliminated(n + 1, false);
        int left = n;
        int clockwise = 1;
        int count = 0;
        int cw = k, ccw = m;

        while (left) {
            int cw_count = 0, ccw_count = 0;
            while (cw_count < cw) {
                count = (count + clockwise + n) % n;
                if (!eliminated[count] && ++cw_count == cw) break;
            }

            while (ccw_count < ccw) {
                count = (count - clockwise + n) % n;
                if (!eliminated[count] && ++ccw_count == ccw) break;
            }

            eliminated[count] = true;
            left--;

            if (cw_count + ccw_count > 0)
                cout << (count == 1 ? " " : ", ") << count;
        }
        cout << endl;
    }
    return 0;
}
