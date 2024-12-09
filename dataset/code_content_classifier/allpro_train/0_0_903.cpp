#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int n;
    cin >> n;

    int max_stable_tower = 1;
    int current_height = 1;

    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    for (int i = 1; i < n; i++) {
        int next_x1, next_y1, next_x2, next_y2;
        cin >> next_x1 >> next_y1 >> next_x2 >> next_y2;

        if (next_x1 >= x1 && next_x2 <= x2 && next_y1 >= y1 && next_y2 <= y2) {
            current_height++;
        } else {
            max_stable_tower = max(max_stable_tower, current_height);
            current_height = 1;
            x1 = next_x1;
            y1 = next_y1;
            x2 = next_x2;
            y2 = next_y2;
        }
    }

    max_stable_tower = max(max_stable_tower, current_height);

    cout << max_stable_tower << endl;

    return 0;
}