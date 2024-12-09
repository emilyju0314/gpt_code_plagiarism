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

        vector<int> horizontal(k);
        for(int i = 0; i < k; i++) {
            cin >> horizontal[i];
        }

        cin >> k;
        vector<int> vertical(k);
        for(int i = 0; i < k; i++) {
            cin >> vertical[i];
        }

        int max_horizontal = *max_element(horizontal.begin(), horizontal.end());
        int min_horizontal = *min_element(horizontal.begin(), horizontal.end());

        int max_vertical = *max_element(vertical.begin(), vertical.end());
        int min_vertical = *min_element(vertical.begin(), vertical.end());

        int max_area = max({min_horizontal * h, (w - max_horizontal) * h, min_vertical * w, (h - max_vertical) * w});

        cout << max_area * 2 << endl;
    }

    return 0;
}