#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> b(n);
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    map<int, int> max_beauty; // Map to store the maximum beauty value ending at each city
    int max_sum = 0; // Maximum beauty value of the journey

    for (int i = 0; i < n; i++) {
        int prev_beauty = b[i] - i; // Beauty value constraint for each city
        
        if (max_beauty.count(prev_beauty)) {
            max_beauty[b[i]] = max(max_beauty[b[i]], max_beauty[prev_beauty] + b[i]);
        } else {
            max_beauty[b[i]] = b[i];
        }

        max_sum = max(max_sum, max_beauty[b[i]]);
    }

    cout << max_sum << endl;

    return 0;
}