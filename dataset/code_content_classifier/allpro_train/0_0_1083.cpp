#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<string> strings(n);
    for(int i = 0; i < n; i++) {
        cin >> strings[i];
    }

    int m = strings[0].size();

    double expected_value = 0.0;
    for(int i = 0; i < m; i++) {
        int count = 0;
        for(int j = 0; j < n; j++) {
            bool unique = true;
            for(int k = 0; k < n; k++) {
                if(j != k && strings[j][i] == strings[k][i]) {
                    unique = false;
                    break;
                }
            }
            if(unique) {
                count++;
            }
        }
        expected_value += 1.0 / count;
    }

    cout.precision(12);
    cout << fixed << expected_value << endl;

    return 0;
}