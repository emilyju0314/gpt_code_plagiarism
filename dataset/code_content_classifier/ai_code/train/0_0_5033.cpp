#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int a1, b1, c1;
        cin >> a1 >> b1 >> c1;

        int a2, b2, c2;
        cin >> a2 >> b2 >> c2;

        vector<int> d(8);
        for (int i = 0; i < 8; i++) {
            cin >> d[i];
        }

        vector<int> f(8, 0);

        for (f[1] = 0; f[1] <= d[1] && f[1] <= a1; f[1]++) {
            for (f[2] = 0; f[2] <= d[2] && f[2] <= b1; f[2]++) {
                for (f[3] = 0; f[3] <= d[3] && f[3] <= c1; f[3]++) {
                    if (f[1] + f[3] <= a1 && f[1] + f[2] <= b1 && f[2] + f[3] <= c1) {
                        int remaining_students = d[1] - f[1] + d[2] - f[2] + d[3] - f[3];
                        for (f[4] = max(0, d[4] - a1 + f[1]); f[4] <= min(d[4], remaining_students); f[4]++) {
                            for (f[5] = max(0, d[5] - b1 + f[2]); f[5] <= min(d[5], remaining_students - f[4]); f[5]++) {
                                for (f[6] = max(0, d[6] - c1 + f[3]); f[6] <= min(d[6], remaining_students - f[4] - f[5]); f[6]++) {
                                    f[7] = remaining_students - f[4] - f[5] - f[6];
                                    if (f[7] >= max(0, d[7] - c1 + f[3]) && f[7] <= min(d[7], remaining_students - f[4] - f[5] - f[6])) {
                                        if (f[4] + f[6] <= a2 && f[4] + f[5] <= b2 && f[5] + f[6] <= c2) {
                                            for (int i = 1; i <= 7; i++) {
                                                cout << f[i] << " ";
                                            }
                                            cout << endl;
                                            return 0;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }

        cout << -1 << endl;
    }

    return 0;
}