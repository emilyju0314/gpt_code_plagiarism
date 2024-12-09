#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int query(int l, int r) {
    cout << "? " << l << " " << r << endl;
    cout.flush();
    int index;
    cin >> index;
    return index;
}

int main() {
    int n;
    cin >> n;

    int max_index = query(1, n);

    if (max_index == 1 || max_index == n) {
        cout << "! " << max_index << endl;
        return 0;
    }

    int left_max_index = query(1, max_index);
    int right_max_index = query(max_index, n);

    int answer = max(left_max_index, right_max_index);

    cout << "! " << answer << endl;

    return 0;
}