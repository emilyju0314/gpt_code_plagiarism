#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    string S, T;
    cin >> S >> T;

    vector<int> positions;
    for (int i = 0; i <= n - m; i++) {
        int errors = 0;
        for (int j = 0; j < m; j++) {
            if (S[i+j] != T[j]) {
                errors++;
            }
        }
        if (errors <= k) {
            positions.push_back(i+1);
        }
    }

    cout << positions.size() << endl;

    return 0;
}