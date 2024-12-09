#include <iostream>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    int v = n;
    while (true) {
        int remaining_lines = n;
        int lines_written = 0;
        while (remaining_lines > 0) {
            lines_written += min(remaining_lines, v);
            remaining_lines -= min(remaining_lines, v);
            remaining_lines -= remaining_lines / k;
        }

        if (lines_written >= n) {
            cout << v << endl;
            break;
        }
        
        v++;
    }

    return 0;
}