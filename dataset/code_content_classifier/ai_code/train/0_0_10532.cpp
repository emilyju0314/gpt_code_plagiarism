#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> requests(n);
    for (int i = 0; i < n; i++) {
        cin >> requests[i];
    }

    map<int, int> freq;
    int maxDifferentBooks = 0;
    int maxFreq = 0;
    int start = 0;

    for (int i = 0; i < n; i++) {
        freq[requests[i]]++;

        while (freq.size() > k) {
            freq[requests[start]]--;
            if (freq[requests[start]] == 0) {
                freq.erase(requests[start]);
            }
            start++;
        }

        maxDifferentBooks = max(maxDifferentBooks, i - start + 1);
    }

    cout << maxDifferentBooks << endl;

    return 0;
}