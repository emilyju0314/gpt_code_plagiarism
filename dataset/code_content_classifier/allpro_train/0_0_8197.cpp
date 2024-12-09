#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m, c;
    cin >> n >> m >> c;

    vector<int> sheets(n, 0);

    for (int i = 0; i < m; i++) {
        int pi;
        cin >> pi;

        int sheet_to_write = 1;
        for (int j = 1; j < n; j++) {
            if (sheets[j] < sheets[sheet_to_write]) {
                sheet_to_write = j;
            }
        }

        cout << sheet_to_write + 1 << endl;
        cout.flush();

        sheets[sheet_to_write] = pi;
        
        if (is_sorted(sheets.begin(), sheets.end())) {
            break;
        }
    }

    return 0;
}