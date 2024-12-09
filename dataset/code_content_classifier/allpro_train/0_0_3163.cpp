#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int q;
    cin >> q;

    for(int i = 0; i < q; i++) {
        int h, w, k;
        cin >> h >> w >> k;

        vector<int> permutation(k);
        for(int j = 0; j < k; j++) {
            permutation[j] = j+1;
        }

        for(int j = 0; j < k; j++) {
            int pos;
            cin >> pos;
            permutation[pos-1] = j+1;
        }

        for(int j = 0; j < k; j++) {
            cout << permutation[j] << " ";
        }
        cout << endl;
    }

    return 0;
}