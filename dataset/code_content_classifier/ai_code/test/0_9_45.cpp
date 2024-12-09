#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        int height = 1;
        int daysWithoutWater = 0;

        for (int i = 0; i < n; i++) {
            if (a[i] == 1) {
                if (i > 0 && a[i-1] == 1) {
                    height += 5;
                } else {
                    height += 1;
                }
                daysWithoutWater = 0;
            } else {
                daysWithoutWater++;
                if (daysWithoutWater == 2) {
                    height = -1;
                    break;
                }
            }
        }

        cout << height << endl;
    }

    return 0;
}