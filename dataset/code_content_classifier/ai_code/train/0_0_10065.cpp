#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

bool isSubarraySumPossible(const vector<int>& a, int k, int sum) {
    unordered_map<int, int> freq;
    int currSum = 0;

    for (int i = 0; i < k; i++) {
        currSum += a[i];
    }
    freq[currSum]++;

    for (int i = k; i < a.size(); i++) {
        currSum -= a[i - k];
        currSum += a[i];
        freq[currSum]++;
    }

    return freq.find(sum) != freq.end();
}

void createBeautifulArray(const vector<int>& a, int n, int k) {
    vector<int> beautifulArray;
    int targetSum = (n * (n + 1)) / (2 * k);

    for (int i = 1; i <= n; i++) {
        if (isSubarraySumPossible(a, k, i)) {
            beautifulArray.push_back(i);
        }
    }

    if (beautifulArray.empty()) {
        cout << "-1\n";
    } else {
        cout << beautifulArray.size() << endl;
        for (int num : beautifulArray) {
            cout << num << " ";
        }
        cout << endl;
    }
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;

        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        createBeautifulArray(a, n, k);
    }

    return 0;
}