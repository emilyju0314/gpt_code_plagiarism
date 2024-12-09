#include <iostream>
#include <vector>

using namespace std;

int countSteps(vector<int>& weights) {
    vector<int> count(40, 0);
    for (int w : weights) {
        count[w]++;
    }

    int ans = 0;
    for (int i = 0; i < count.size(); i++) {
        if (count[i] > 0) {
            ans++;
            int j = i;
            while (count[j] > 0) {
                count[j]--;
                j++;
            }
        }
    }
    return ans;
}

int main() {
    int n;
    cin >> n;

    vector<int> weights(n);
    for (int i = 0; i < n; i++) {
        cin >> weights[i];
    }

    cout << countSteps(weights) << endl;

    return 0;
}