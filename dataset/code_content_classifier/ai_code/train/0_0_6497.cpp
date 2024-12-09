#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<long long> max_salaries(n, 0);
    long long max_diff = 0;

    for(int i = 0; i < n; i++) {
        int m;
        cin >> m;

        vector<long long> salaries(m);
        for(int j = 0; j < m; j++) {
            cin >> salaries[j];
        }

        max_salaries[i] = *max_element(salaries.begin(), salaries.end());

        if(i > 0) {
            max_diff = max(max_diff, abs(max_salaries[i] - max_salaries[i - 1]));
        }
    }

    long long total_increase = 0;
    for(int i = 0; i < n; i++) {
        total_increase += (max_salaries[i] - max_salaries[0]);
    }

    cout << total_increase << endl;

    return 0;
}