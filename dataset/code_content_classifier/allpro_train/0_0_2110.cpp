#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, W;
    cin >> N >> W;

    vector<int> ni(N);
    for (int i = 0; i < N; i++) {
        cin >> ni[i];
    }

    vector<int> schedule;
    int y = 0;

    for (int i = 0; i < N; i++) {
        while (ni[i] > 0) {
            if (y + ni[i] <= W) {
                for (int j = 0; j < ni[i]; j++) {
                    schedule.push_back(i+1);
                }
                y += ni[i];
                ni[i] = 0;
            } else {
                for (int j = 0; j < W - y; j++) {
                    schedule.push_back(i+1);
                }
                break;
            }
        }
    }

    if (y == W) {
        cout << "Yes" << endl;
        for (int i = 0; i < schedule.size(); i++) {
            cout << schedule[i] << " ";
        }
        cout << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}