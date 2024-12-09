#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> cakes(n);
    for (int i = 0; i < n; i++) {
        cin >> cakes[i];
    }

    unordered_map<int, int> cakeCount;
    int distinctTypes = 0;
    int totalValue = 0;
    int left = 0;

    for (int right = 0; right < n; right++) {
        if (cakeCount[cakes[right]] == 0) {
            distinctTypes++;
        }
        cakeCount[cakes[right]]++;

        while (distinctTypes > k) {
            cakeCount[cakes[left]]--;
            if (cakeCount[cakes[left]] == 0) {
                distinctTypes--;
            }
            left++;
        }

        totalValue = max(totalValue, right - left + 1);
    }

    cout << totalValue << endl;

    return 0;
}