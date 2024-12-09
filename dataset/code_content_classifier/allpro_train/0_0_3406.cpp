#include <iostream>
#include <map>

using namespace std;

int main() {
    int n;
    cin >> n;

    map<int, int> boxes;

    for (int i = 0; i < n; i++) {
        int ki, ai;
        cin >> ki >> ai;
        boxes[ki] += ai;
    }

    int max_ki = -1;
    for (auto it = boxes.begin(); it != boxes.end(); it++) {
        max_ki = max(max_ki, it->first);
        if (it->second >= 4) {
            boxes[it->first + 1] += it->second / 4;
            it->second %= 4;
        }
    }

    while (boxes[max_ki] == 0) {
        max_ki--;
    }

    cout << max_ki + 1 << endl;

    return 0;
}