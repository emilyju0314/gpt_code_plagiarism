#include <iostream>
#include <vector>

using namespace std;

int main() {
    int q;
    cin >> q;

    vector<int> arr;
    for (int i = 0; i < q; i++) {
        int type, x, y;
        cin >> type >> x;
        if (type == 1) {
            arr.push_back(x);
        } else {
            cin >> y;
            for (int j = 0; j < arr.size(); j++) {
                if (arr[j] == x) {
                    arr[j] = y;
                }
            }
        }
    }

    for (int num : arr) {
        cout << num << " ";
    }

    return 0;
}