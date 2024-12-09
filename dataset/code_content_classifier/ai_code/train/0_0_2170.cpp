#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    int t;
    cin >> t;

    vector<int> sequence(t);
    unordered_map<int, int> freq;

    for(int i = 0; i < t; i++) {
        cin >> sequence[i];
        freq[sequence[i]]++;
    }

    int n = -1, m = -1, x = -1, y = -1;
    for(int i = 1; i * i <= t; i++) {
        if(t % i == 0) {
            if(freq[0] >= 1 && freq[0] + freq[i] == t/i && freq[i] * freq[t/i] == freq[0]) {
                n = t/i;
                m = i;
                x = freq[i] + 1;
                y = freq[0] / x + 1;
                break;
            } else if(freq[0] >= 1 && freq[0] + freq[t/i] == t/i && freq[i] * freq[t/i] == freq[0]) {
                n = i;
                m = t/i;
                x = freq[t/i] + 1;
                y = freq[0] / x + 1;
                break;
            }
        }
    }

    if(n == -1 || m == -1 || x == -1 || y == -1) {
        cout << -1 << endl;
    } else {
        cout << n << " " << m << endl;
        cout << x << " " << y << endl;
    }

    return 0;
}