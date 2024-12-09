#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int w, h;
        cin >> w >> h;

        int k;
        cin >> k;
        vector<int> horizontal1(k);
        for (int i = 0; i < k; i++) {
            cin >> horizontal1[i];
        }

        cin >> k;
        vector<int> horizontal2(k);
        for (int i = 0; i < k; i++) {
            cin >> horizontal2[i];
        }

        cin >> k;
        vector<int> vertical1(k);
        for (int i = 0; i < k; i++) {
            cin >> vertical1[i];
        }

        cin >> k;
        vector<int> vertical2(k);
        for (int i = 0; i < k; i++) {
            cin >> vertical2[i];
        }

        int max_area = 0;

        for (int i = 0; i < horizontal1.size(); i++) {
            for (int j = 0; j < vertical1.size(); j++) {
                if ((horizontal1[i] != 0 || vertical1[j] != 0) && (horizontal1[i] != w || vertical1[j] != h)) {
                    max_area = max(max_area, min(horizontal1[i], w - horizontal1[i]) * h);
                    max_area = max(max_area, min(vertical1[j], h - vertical1[j]) * w);
                }
            }
        }

        cout << max_area * 2 << endl;
    }

    return 0;
}