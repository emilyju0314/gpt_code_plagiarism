#include <iostream>
#include <vector>

using namespace std;

int main() {
    int p, q, l, r;
    cin >> p >> q >> l >> r;

    vector<pair<int, int>> Zschedule(p);
    vector<pair<int, int>> Xschedule(q);

    for (int i = 0; i < p; i++) {
        cin >> Zschedule[i].first >> Zschedule[i].second;
    }

    for (int i = 0; i < q; i++) {
        cin >> Xschedule[i].first >> Xschedule[i].second;
    }

    int count = 0;
    for (int t = l; t <= r; t++) {
        bool canChat = false;
        for (int i = 0; i < q; i++) {
            for (int j = 0; j < p; j++) {
                if (Xschedule[i].second + t >= Zschedule[j].first && Xschedule[i].first + t <= Zschedule[j].second) {
                    canChat = true;
                    break;
                }
            }
            if (canChat) {
                break;
            }
        }
        if (canChat) {
            count++;
        }
    }

    cout << count << endl;

    return 0;
}