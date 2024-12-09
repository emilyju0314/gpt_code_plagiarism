#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    int n;
    cin >> n;

    set<int> weights;

    for (int i = 1; i <= n; i++) {
        int sum = n;
        vector<int> split;
        while (sum > 0) {
            split.push_back(min(i, sum));
            sum -= min(i, sum);
        }

        int weight = 1;
        for (int j = 1; j < split.size(); j++) {
            if (split[j] == split[0]) {
                weight++;
            } else {
                break;
            }
        }

        weights.insert(weight);
    }

    cout << weights.size() << endl;

    return 0;
}