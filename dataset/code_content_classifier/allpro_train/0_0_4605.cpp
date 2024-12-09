#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> arraySizes(n);
    for (int i = 0; i < n; i++) {
        cin >> arraySizes[i];
    }

    vector<int> c(k);
    for (int i = 0; i < k; i++) {
        cin >> c[i];
    }

    sort(arraySizes.begin(), arraySizes.end(), greater<int>());

    int currentArray = 0;
    vector<vector<int>> testcases;
    while (currentArray < n) {
        vector<int> testcase;
        for (int i = 0; i < k && currentArray < n; i++) {
            while (c[i] > 0 && currentArray < n) {
                testcase.push_back(arraySizes[currentArray]);
                c[i]--;
                currentArray++;
            }
        }
        testcases.push_back(testcase);
    }

    cout << testcases.size() << endl;
    for (int i = 0; i < testcases.size(); i++) {
        cout << testcases[i].size();
        for (int j = 0; j < testcases[i].size(); j++) {
            cout << " " << testcases[i][j];
        }
        cout << endl;
    }

    return 0;
}