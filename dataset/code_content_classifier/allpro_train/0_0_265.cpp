#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> problems(n);
        for (int i = 0; i < n; i++) {
            cin >> problems[i];
        }

        int g = 0, s = 0, b = 0;

        if (n < 3) {
            cout << "0 0 0" << endl;
            continue;
        }

        int totalMedals = n / 2;

        for (int i = 0; i < totalMedals; i++) {
            if (problems[i] > problems[totalMedals]) {
                g++;
            }
        }

        for (int i = totalMedals; i < 2 * totalMedals; i++) {
            if (problems[i] > problems[2 * totalMedals]) {
                s++;
            }
        }

        b = totalMedals - g - s;

        cout << g << " " << s << " " << b << endl;
    }

    return 0;
}