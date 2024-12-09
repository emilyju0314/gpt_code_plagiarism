#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<string> field(n);
    for (int i = 0; i < n; i++) {
        cin >> field[i];
    }

    int max_count = 0;
    pair<int, int> result;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (field[i][j] == '.') {
                // Check horizontally
                int count = 0;
                bool valid = true;
                for (int x = 0; x < k; x++) {
                    if (j + x >= n || field[i][j + x] == '#') {
                        valid = false;
                        break;
                    }
                    count++;
                }
                if (valid && count > max_count) {
                    max_count = count;
                    result = {i+1, j+1};
                }

                // Check vertically
                count = 0;
                valid = true;
                for (int y = 0; y < k; y++) {
                    if (i + y >= n || field[i + y][j] == '#') {
                        valid = false;
                        break;
                    }
                    count++;
                }
                if (valid && count > max_count) {
                    max_count = count;
                    result = {i+1, j+1};
                }
            }
        }
    }

    cout << result.first << " " << result.second << endl;

    return 0;
}