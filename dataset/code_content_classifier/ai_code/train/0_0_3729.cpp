#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    vector<int> count(k, 0);
    for (int i = 0; i < n; i++) {
        count[s[i] - 'A']++;
    }

    int minCount = *min_element(count.begin(), count.end());

    cout << minCount * k << endl;

    return 0;
}