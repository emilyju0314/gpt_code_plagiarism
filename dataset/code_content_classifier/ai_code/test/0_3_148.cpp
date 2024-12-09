#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int w, h;
        cin >> w >> h;

        int k;
        cin >> k;
        vector<int> horizontal_top(k);
        for(int i = 0; i < k; i++) {
            cin >> horizontal_top[i];
        }

        cin >> k;
        vector<int> horizontal_bottom(k);
        for(int i = 0; i < k; i++) {
            cin >> horizontal_bottom[i];
        }

        cin >> k;
        vector<int> vertical_left(k);
        for(int i = 0; i < k; i++) {
            cin >> vertical_left[i];
        }

        cin >> k;
        vector<int> vertical_right(k);
        for(int i = 0; i < k; i++) {
            cin >> vertical_right[i];
        }

        // Choose 3 points such that exactly 2 belong to the same side
        int max_area = 0;

        // Horizontal sides
        for(int i = 0; i < horizontal_top.size(); i++) {
            for(int j = 0; j < horizontal_bottom.size(); j++) {
                int base = horizontal_bottom[j] - horizontal_top[i];
                int height = min(horizontal_top[i], h - horizontal_top[i]);
                int area = base*height;
                max_area = max(max_area, area);
            }
        }

        // Vertical sides
        for(int i = 0; i < vertical_left.size(); i++) {
            for(int j = 0; j < vertical_right.size(); j++) {
                int base = vertical_right[j] - vertical_left[i];
                int height = min(vertical_left[i], w - vertical_left[i]);
                int area = base*height;
                max_area = max(max_area, area);
            }
        }

        // Diagonal
        for(int i = 0; i < horizontal_top.size(); i++) {
            for(int j = 0; j < vertical_left.size(); j++) {
                int base = vertical_left[j];
                int height = horizontal_top[i];
                int area = base*height;
                max_area = max(max_area, area);
            }
            for(int j = 0; j < vertical_right.size(); j++) {
                int base = w - vertical_right[j];
                int height = horizontal_top[i];
                int area = base*height;
                max_area = max(max_area, area);
            }
        }

        cout << 2*max_area << endl;
    }

    return 0;
}