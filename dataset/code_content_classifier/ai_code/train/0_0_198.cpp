#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
    int n, b;
    cin >> n >> b;

    vector<pair<pair<int, int>, pair<int, int>>> arrows;
    unordered_map<int, char> grid;

    for (int i = 0; i < n; i++) {
        int x0, y0, x1, y1;
        cin >> x0 >> y0 >> x1 >> y1;
        arrows.push_back({{x0, y0}, {x1, y1}});

        if (x0 == x1) {
            for (int y = min(y0, y1); y <= max(y0, y1); y++) {
                grid[x0 * b + y] = 'V';
            }
        } else {
            for (int x = min(x0, x1); x <= max(x0, x1); x++) {
                grid[x * b + y0] = 'H';
            }
        }
    }

    int q;
    cin >> q;

    for (int i = 0; i < q; i++) {
        int xi, yi, ti;
        char wi;
        cin >> xi >> yi >> wi >> ti;

        if (grid.find(xi * b + yi) == grid.end()) {
            cout << xi << " " << yi << endl;
            continue;
        }

        while (ti > 0) {
            if (wi == 'U') {
                int y_next = yi;
                for (int y = yi + 1; y <= b; y++) {
                    if (grid.find(xi * b + y) != grid.end()) {
                        y_next = y - 1;
                        break;
                    }
                }
                ti -= y_next - yi + 1;
                yi = y_next;
            } else if (wi == 'D') {
                int y_next = yi;
                for (int y = yi - 1; y >= 0; y--) {
                    if (grid.find(xi * b + y) != grid.end()) {
                        y_next = y + 1;
                        break;
                    }
                }
                ti -= yi - y_next + 1;
                yi = y_next;
            } else if (wi == 'L') {
                int x_next = xi;
                for (int x = xi - 1; x >= 0; x--) {
                    if (grid.find(x * b + yi) != grid.end()) {
                        x_next = x + 1;
                        break;
                    }
                }
                ti -= xi - x_next + 1;
                xi = x_next;
            } else if (wi == 'R') {
                int x_next = xi;
                for (int x = xi + 1; x <= b; x++) {
                    if (grid.find(x * b + yi) != grid.end()) {
                        x_next = x - 1;
                        break;
                    }
                }
                ti -= x_next - xi + 1;
                xi = x_next;
            }

            if (ti <= 0 || grid.find(xi * b + yi) == grid.end()) {
                break;
            }
            if (grid[xi * b + yi] == 'H') {
                if (wi == 'U' || wi == 'D') {
                    wi = (wi == 'U') ? 'D' : 'U';
                }
            } else {
                if (wi == 'L' || wi == 'R') {
                    wi = (wi == 'L') ? 'R' : 'L';
                }
            }
        }

        cout << xi << " " << yi << endl;
    }

    return 0;
}