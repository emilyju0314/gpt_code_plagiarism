#include <iostream>
#include <string>
#include <vector>

using namespace std;

void query(int k_a, vector<int>& a, int k_b, vector<int>& b) {
    cout << "? " << k_a << " " << k_b << endl;
    for (int i = 0; i < k_a; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < k_b; i++) {
        cout << b[i] << " ";
    }
    cout << endl;
    cout.flush();
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int n, k;
        cin >> n >> k;

        vector<int> a, b;
        for (int i = 1; i <= n; i++) {
            if (i % 2 == 1) {
                a.push_back(i);
            } else {
                b.push_back(i);
            }
        }

        int low = 1, high = n;
        while (low < high) {
            int mid = (low + high) / 2;
            vector<int> a_subset, b_subset;

            for (int i = 0; i < a.size(); i++) {
                if (a[i] <= mid) {
                    a_subset.push_back(a[i]);
                }
            }

            for (int i = 0; i < b.size(); i++) {
                if (b[i] <= mid) {
                    b_subset.push_back(b[i]);
                }
            }

            query(a_subset.size(), a_subset, b_subset.size(), b_subset);
            string response;
            cin >> response;

            if (response == "FIRST") {
                high = mid;
            } else {
                low = mid + 1;
            }
        }

        cout << "! " << low << endl;
        cout.flush();
    }

    return 0;
}