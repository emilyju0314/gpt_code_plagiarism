#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<string> symbols(n);
    for(int i = 0; i < n; i++) {
        cin >> symbols[i];
    }

    int minOperations = INT_MAX;
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < m; j++) {
            for(int k = 0; k < m; k++) {
                if(i == j || j == k || i == k) continue;

                int operations = 0;
                for(int l = 0; l < n; l++) {
                    if(symbols[l][i] >= '0' && symbols[l][i] <= '9') continue;
                    if(symbols[l][j] >= 'a' && symbols[l][j] <= 'z') continue;
                    if(symbols[l][k] == '#' || symbols[l][k] == '*' || symbols[l][k] == '&') continue;

                    int dist1 = min(abs(i - j), m - abs(i - j));
                    int dist2 = min(abs(i - k), m - abs(i - k));
                    int dist3 = min(abs(j - k), m - abs(j - k));

                    operations += min(dist1, min(dist2, dist3));
                }

                minOperations = min(minOperations, operations);
            }
        }
    }

    cout << minOperations << endl;

    return 0;
}