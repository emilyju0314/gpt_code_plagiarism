#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> colors(n);
    for(int i = 0; i < n; i++) {
        cin >> colors[i];
    }

    vector<int> desiredCounts(m);
    for(int i = 0; i < m; i++) {
        cin >> desiredCounts[i];
    }

    vector<int> actualCounts(m, 0);
    int left = 0, right = 0;
    int uniqueColors = 0;
    string result = "NO";

    while(right < n) {
        if(actualCounts[colors[right]-1] == 0) {
            uniqueColors++;
        }
        actualCounts[colors[right]-1]++;

        while(uniqueColors == m) {
            if(right - left + 1 == m) {
                bool valid = true;
                for(int i = 0; i < m; i++) {
                    if(actualCounts[i] != desiredCounts[i]) {
                        valid = false;
                        break;
                    }
                }
                if(valid) {
                    result = "YES";
                    break;
                }
            }

            actualCounts[colors[left]-1]--;
            if(actualCounts[colors[left]-1] == 0) {
                uniqueColors--;
            }
            left++;
        }

        right++;
    }

    cout << result << endl;

    return 0;
}