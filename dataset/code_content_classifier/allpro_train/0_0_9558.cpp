#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<string> strings(n);
    map<string, int> freqMap;

    for (int i = 0; i < n; i++) {
        cin >> strings[i];
        for (int l = 0; l < strings[i].size(); l++) {
            for (int r = l; r < strings[i].size(); r++) {
                freqMap[strings[i].substr(l, r - l + 1)]++;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        int count = 0;
        for (int l = 0; l < strings[i].size(); l++) {
            for (int r = l; r < strings[i].size(); r++) {
                if (freqMap[strings[i].substr(l, r - l + 1)] >= k) {
                    count++;
                }
            }
        }
        cout << count << " ";
    }

    return 0;
}