#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n), b(n), c(n);
    unordered_map<int, int> freq;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        freq[a[i]]++;
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        freq[b[i]]++;
    }
    for (int i = 0; i < n; i++) {
        cin >> c[i];
        freq[c[i]]++;
    }

    vector<int> uniqueNums;
    for (auto& it : freq) {
        uniqueNums.push_back(it.first);
    }

    sort(uniqueNums.begin(), uniqueNums.end());

    long long minSum = n * 3; // Initialize minSum with a value that always be greater than the sum of the elements

    unordered_map<int, int> aFreq, bFreq, cFreq;
    for (int num : uniqueNums) {
        aFreq[num] = bFreq[num] = cFreq[num] = 0;
    }

    int aIdx = 0, bIdx = 0, cIdx = 0;

    for (int i = 0; i < n * 3; i++) {
        while (aIdx < n && aFreq[a[aIdx]] == 0) {
            aFreq[a[aIdx]]++;
            aIdx++;
        }
        while (bIdx < n && bFreq[b[bIdx]] == 0) {
            bFreq[b[bIdx]]++;
            bIdx++;
        }
        while (cIdx < n && cFreq[c[cIdx]] == 0) {
            cFreq[c[cIdx]]++;
            cIdx++;
        }

        minSum = min(minSum, n + bIdx + cIdx - aIdx * 2);

        aFreq[a[i % n]]--;
        bFreq[b[i % n]]--;
        cFreq[c[i % n]]--;
    }

    cout << minSum << endl;

    return 0;
}