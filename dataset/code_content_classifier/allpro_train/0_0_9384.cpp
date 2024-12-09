#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int T;
    cin >> T;

    for (int t = 0; t < T; t++) {
        int N;
        cin >> N;

        vector<pair<int, int>> boxes;

        for (int i = 0; i < 2*N - 1; i++) {
            int a, o;
            cin >> a >> o;
            boxes.push_back(make_pair(a, o));
        }

        sort(boxes.begin(), boxes.end());

        vector<int> chosen_boxes;

        for (int i = 0; i < N; i++) {
            chosen_boxes.push_back(i + 1);
        }

        cout << "YES" << endl;

        for (int i = 0; i < N; i++) {
            cout << chosen_boxes[i] << " ";
        }

        cout << endl;
    }

    return 0;
}