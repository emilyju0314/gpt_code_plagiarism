#include <iostream>
#include <vector>

using namespace std;

int main() {
    int k1, k2, k3;
    cin >> k1 >> k2 >> k3;

    vector<int> problems(k1 + k2 + k3 + 1, 0);

    for (int i = 1; i <= k1; i++) {
        int num;
        cin >> num;
        problems[num] = 1;
    }

    for (int i = 1; i <= k2; i++) {
        int num;
        cin >> num;
        problems[num] = 2;
    }

    for (int i = 1; i <= k3; i++) {
        int num;
        cin >> num;
        problems[num] = 3;
    }

    int moves = 0;
    int prefix = 0, suffix = 0;

    for (int i = 1; i <= k1 + k2 + k3; i++) {
        if (problems[i] == 1) {
            prefix++;
        } else if (problems[i] == 3) {
            suffix++;
        } else {
            if (prefix + suffix < k1) {
                prefix++;
                moves++;
            } else {
                suffix++;
                moves++;
            }
        }
    }

    cout << moves << endl;

    return 0;
}