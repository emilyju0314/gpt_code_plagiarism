#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    string S;
    cin >> S;

    int backward_steps = 0;
    vector<int> footprints;
    int count_r = 0, count_l = 0;

    for (int i = 0; i < S.length(); i++) {
        if (S[i] == 'R') {
            count_r++;
            footprints.push_back(i + 1);
        } else {
            count_l++;
            footprints.insert(footprints.begin() + count_r, i + 1);
        }
    }

    if (count_r < count_l) {
        backward_steps = count_r;
    } else {
        backward_steps = count_l;
    }

    cout << backward_steps << endl;
    for (int i = 0; i < footprints.size(); i++) {
        cout << footprints[i] << " ";
    }

    return 0;
}