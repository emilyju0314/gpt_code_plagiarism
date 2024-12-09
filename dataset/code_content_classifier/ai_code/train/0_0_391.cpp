#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> pebbles(n);
    for(int i = 0; i < n; i++) {
        cin >> pebbles[i];
    }

    int days = 0;
    while(true) {
        bool collectedAll = true;
        for(int i = 0; i < n; i++) {
            if(pebbles[i] > 0) {
                pebbles[i] = max(0, pebbles[i] - k);
                collectedAll = false;
            }
        }
        if(collectedAll) {
            break;
        }
        days++;
    }

    cout << days << endl;

    return 0;
}