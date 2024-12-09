#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> p(n);
        for (int i = 0; i < n; i++) {
            cin >> p[i];
        }

        vector<int> result;
        int currMax = n + 1;

        for (int i = n - 1; i >= 0; i--) {
            if (p[i] > currMax) {
                break;
            } else {
                if (p[i] < currMax) {
                    currMax = p[i];
                    result.insert(result.begin(), p[i]);
                } else {
                    result.push_back(p[i]);
                    currMax = p[i];
                }
            }
        }

        for (int i = 0; i < result.size(); i++) {
            cout << result[i] << " ";
        }
        cout << endl;
    }

    return 0;
}