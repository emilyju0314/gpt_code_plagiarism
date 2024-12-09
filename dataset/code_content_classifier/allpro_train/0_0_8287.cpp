#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> blocks1(n);
    vector<int> blocks2(m);

    for (int i = 0; i < n; i++) {
        cin >> blocks1[i];
    }

    for (int i = 0; i < m; i++) {
        cin >> blocks2[i];
    }

    int i = 0, j = 0, files = 0, sum1 = blocks1[0], sum2 = blocks2[0];

    while (i < n && j < m) {
        if (sum1 == sum2) {
            files++;
            i++;
            j++;
            if (i < n) sum1 += blocks1[i];
            if (j < m) sum2 += blocks2[j];
        } else if (sum1 < sum2) {
            i++;
            if (i < n) sum1 += blocks1[i];
        } else {
            j++;
            if (j < m) sum2 += blocks2[j];
        }
    }

    cout << files << endl;

    return 0;
}