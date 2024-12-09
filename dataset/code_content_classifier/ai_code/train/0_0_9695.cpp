#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> c(10);
    for (int i = 0; i < 10; i++) {
        cin >> c[i];
    }

    string result;

    while (n > 0) {
        int minIndex = -1;
        for (int i = 1; i < 10; i++) {
            if (c[i] <= c[minIndex] || minIndex == -1) {
                minIndex = i;
            }
        }

        if (c[minIndex] > m) {
            break;
        }

        result += to_string(minIndex);
        m -= c[minIndex];
        n--;
    }

    if (result.empty()) {
        cout << "NA" << endl;
    } else {
        while (m >= c[0]) {
            result = "0" + result;
            m -= c[0];
        }
        cout << result << endl;
    }

    return 0;
}