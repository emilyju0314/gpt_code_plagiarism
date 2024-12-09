#include <iostream>
#include <vector>

using namespace std;

vector<int> calculateCounts(int n, int k, long long x) {
    vector<int> counts(n, 0);
    counts[0] = 1;

    long long total = 1;
    for(int i = 1; i < n; i++) {
        if(x - total >= k) {
            counts[i] = k;
            total += k;
        } else {
            counts[i] = x - total;
            total = x;
        }
    }

    return counts;
}

int main() {
    int t;
    cin >> t;

    for(int i = 0; i < t; i++) {
        int n, k;
        long long x;
        cin >> n >> k >> x;

        string s;
        cin >> s;

        vector<int> counts = calculateCounts(n, k, x);

        string result = "";
        char prev = 'a';
        for(int j = 0; j < n; j++) {
            if(s[j] == 'a') {
                result += prev;
            } else {
                for(int l = 0; l < counts[j]; l++) {
                    result += prev;
                }
                if(prev < 'a' + k) {
                    prev++;
                }
            }
        }

        cout << result << endl;
    }

    return 0;
}