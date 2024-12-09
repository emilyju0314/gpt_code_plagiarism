#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }

    int max_records = 0;
    int element_to_remove = -1;

    for (int i = 0; i < n; i++) {
        int records = 0;
        bool removed = false;

        for (int j = 0; j < n; j++) {
            if (j == i) {
                removed = true;
                continue;
            }

            if (j < i && p[j] < p[i]) {
                records++;
            } else if (j > i && p[j] > p[i]) {
                records++;
            }
        }

        if (records > max_records) {
            max_records = records;
            element_to_remove = p[i];
        } else if (records == max_records && element_to_remove > p[i]) {
            element_to_remove = p[i];
        }
    }

    cout << element_to_remove << endl;

    return 0;
}