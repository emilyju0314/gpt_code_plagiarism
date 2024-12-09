#include <iostream>
#include <vector>

using namespace std;

int main() {
    string weights;
    cin >> weights;
    int m;
    cin >> m;

    vector<int> left, right;
    int total_left = 0, total_right = 0;

    for (int i = 0; i < weights.size(); i++) {
        if (weights[i] == '1') {
            if (i % 2 == 0) {
                left.push_back(i+1);
                total_left += i+1;
            } else {
                right.push_back(i+1);
                total_right += i+1;
            }
        }
    }

    if (total_left <= total_right) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
        for (int i = 0; i < m; i++) {
            if (i % 2 == 0) {
                cout << left.front() << " ";
                left.erase(left.begin());
            } else {
                cout << right.front() << " ";
                right.erase(right.begin());
            }
        }
        cout << endl;
    }

    return 0;
}