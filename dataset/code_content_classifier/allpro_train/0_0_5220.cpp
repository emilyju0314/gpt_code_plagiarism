#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, a, b;
        cin >> n >> a >> b;
        
        string s;
        cin >> s;

        vector<int> points;
        int consecutive = 1;

        for (int i = 1; i < n; i++) {
            if (s[i] == s[i-1]) {
                consecutive++;
            } else {
                points.push_back(consecutive);
                consecutive = 1;
            }
        }

        points.push_back(consecutive);

        int totalPoints = a * n + b;
        for (int len : points) {
            totalPoints += max(a * len + b, len * (a + b));
        }

        cout << totalPoints << endl;
    }

    return 0;
}