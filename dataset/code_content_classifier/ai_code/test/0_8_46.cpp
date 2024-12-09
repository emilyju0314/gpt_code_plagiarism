#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int eversionIterations(vector<int>& a) {
    int n = a.size();
    unordered_map<int, int> index;
    for (int i = 0; i < n; i++) {
        index[a[i]] = i;
    }

    int iterations = 0;
    for (int i = n; i >= 1; i--) {
        if (index[i] != i - 1) {
            iterations++;
            for (int j = 0; j < index[i]; j++) {
                if (a[j] > i) {
                    return iterations;
                }
            }
        }
    }

    return 0;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        cout << eversionIterations(a) << endl;
    }

    return 0;
}