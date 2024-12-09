#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int countInversions(vector<string> arr) {
    int inv_count = 0;
    for (int i = 0; i < arr.size(); i++) {
        for (int j = i + 1; j < arr.size(); j++) {
            if (arr[i] > arr[j]) {
                inv_count++;
            }
        }
    }
    return inv_count;
}

int main() {
    int n;
    cin >> n;

    vector<string> lesha(n);
    for (int i = 0; i < n; i++) {
        cin >> lesha[i];
    }

    int m;
    cin >> m;

    int best_index = -1;
    int best_similarity = -1;

    for (int i = 0; i < m; i++) {
        int k;
        cin >> k;

        vector<string> archive(k);
        for (int j = 0; j < k; j++) {
            cin >> archive[j];
        }

        if (k < n) {
            continue;
        }

        int max_similarity = 0;
        do {
            bool found = false;
            int idx = 0;

            for (int j = 0; j < k && idx < n; j++) {
                if (archive[j] == lesha[idx]) {
                    idx++;
                }
            }

            if (idx == n) {
                int similarity = countInversions(lesha);
                if (similarity > max_similarity) {
                    max_similarity = similarity;
                }
                found = true;
            }

            if (found) {
                if (max_similarity > best_similarity) {
                    best_similarity = max_similarity;
                    best_index = i+1;
                }
            }
        } while (next_permutation(lesha.begin(), lesha.end()));
    }

    if (best_index == -1) {
        cout << "Brand new problem!" << endl;
    } else {
        cout << best_index << endl;
        cout << "[:";
        for (int i = 0; i < best_similarity; i++) {
            cout << "|";
        }
        cout << ":]" << endl;
    }

    return 0;
}