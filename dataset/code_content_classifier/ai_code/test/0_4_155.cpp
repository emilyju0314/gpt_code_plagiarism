#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> p(n);
        vector<int> liked_indices;
        vector<int> disliked_indices;
        for (int i = 0; i < n; i++) {
            cin >> p[i];
            if (p[i] == 1) {
                liked_indices.push_back(i);
            } else {
                disliked_indices.push_back(i);
            }
        }

        string s;
        cin >> s;

        sort(liked_indices.begin(), liked_indices.end());
        sort(disliked_indices.begin(), disliked_indices.end());

        vector<int> q(n);
        int liked_idx = 0;
        int disliked_idx = 0;

        for (int i = 0; i < n; i++) {
            if (s[i] == '0') {
                q[disliked_indices[disliked_idx++]] = i + 1;
            } else {
                q[liked_indices[liked_idx++]] = i + 1;
            }
        }

        for (int i = 0; i < n; i++) {
            cout << q[i] << " ";
        }
        cout << endl;
    }

    return 0;
}