#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;

        vector<int> days(n);
        for (int j = 0; j < n; j++) {
            cin >> days[j];
        }

        int height = 1;
        int consecutive_unwatered_days = 0;
        for (int j = 0; j < n; j++) {
            if (days[j] == 1) {
                if (consecutive_unwatered_days >= 1) {
                    height += 4; // 5 - 1 = 4 additional centimeters
                } else {
                    height++;
                }
                consecutive_unwatered_days = 0;
            } else {
                consecutive_unwatered_days++;
                if (consecutive_unwatered_days >= 2) {
                    cout << -1 << endl; // Flower dies
                    break;
                }
            }
        }

        if (consecutive_unwatered_days < 2) {
            cout << height << endl; // Flower survives
        }
    }

    return 0;
}