#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    int r, c, n, k;
    cin >> r >> c >> n >> k;

    vector<pair<int, int>> viola_positions;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        viola_positions.push_back({x, y});
    }

    int count = 0;
    for (int x1 = 1; x1 <= r; x1++) {
        for (int x2 = x1; x2 <= r; x2++) {
            for (int y1 = 1; y1 <= c; y1++) {
                for (int y2 = y1; y2 <= c; y2++) {
                    int viola_count = 0;
                    set<pair<int, int>> curr_rectangle;
                    for (int i = 0; i < n; i++) {
                        int x = viola_positions[i].first;
                        int y = viola_positions[i].second;
                        if (x >= x1 && x <= x2 && y >= y1 && y <= y2) {
                            viola_count++;
                            curr_rectangle.insert(viola_positions[i]);
                        }
                    }
                    if (viola_count >= k && curr_rectangle.size() == k) {
                        count++;
                    }
                }
            }
        }
    }

    cout << count << endl;

    return 0;
}