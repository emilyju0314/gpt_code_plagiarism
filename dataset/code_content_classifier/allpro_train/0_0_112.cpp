#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, x;
    cin >> n >> x;

    vector<int> beavers(n);
    for (int i = 0; i < n; i++) {
        cin >> beavers[i];
    }

    vector<int> positions;
    for (int i = 0; i < n; i++) {
        int curr = i + 1;
        bool isValid = true;
        
        while (curr != 0) {
            if (curr == x) {
                isValid = false;
                break;
            }
            curr = beavers[curr - 1];
        }
        
        if (isValid) {
            positions.push_back(i + 1);
        }
    }

    for (int pos : positions) {
        cout << pos << endl;
    }

    return 0;
}