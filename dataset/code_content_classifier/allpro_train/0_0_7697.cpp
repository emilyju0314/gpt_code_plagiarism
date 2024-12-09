#include <iostream>
#include <vector>

using namespace std;

int gcd(int a, int b) {
    if (a == 0)
        return b;
    return gcd(b % a, a);
}

int maxPairs(vector<int>& blue, vector<int>& red) {
    int max_pairs = 0;
    bool matched = true;
    while (matched) {
        int matches = 0;
        vector<int> red_available(red.size(), 1);
        for (int i = 0; i < blue.size(); i++) {
            for (int j = 0; j < red.size(); j++) {
                if (red_available[j] && gcd(blue[i], red[j]) > 1) {
                    matches++;
                    red_available[j] = 0;
                    break;
                }
            }
        }
        if (matches == 0)
            matched = false;
        else
            max_pairs += matches;
    }
    return max_pairs;
}

int main() {
    int m, n;
    while (cin >> m >> n) {
        if (m == 0 && n == 0)
            break;
        vector<int> blue(m), red(n);
        for (int i = 0; i < m; i++)
            cin >> blue[i];
        for (int i = 0; i < n; i++)
            cin >> red[i];
        int result = maxPairs(blue, red);
        cout << result << endl;
    }
    return 0;
}