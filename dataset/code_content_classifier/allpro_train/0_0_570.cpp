#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> firstList(n);
    vector<int> secondList(m);

    for (int i = 0; i < n; i++) {
        cin >> firstList[i];
    }

    for (int i = 0; i < m; i++) {
        cin >> secondList[i];
    }

    sort(firstList.begin(), firstList.end());
    sort(secondList.begin(), secondList.end());

    int minPretty = 10;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int num = firstList[i] * 10 + secondList[j];
            minPretty = min(minPretty, num);
            num = secondList[j] * 10 + firstList[i];
            minPretty = min(minPretty, num);
        }
    }

    cout << minPretty << endl;

    return 0;
}