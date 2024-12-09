#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int x, k;
    cin >> x >> k;

    vector<int> rounds;
    vector<int> div1_rounds;
    vector<int> div2_rounds;

    for (int i = 0; i < k; i++) {
        int type, num1, num2;
        cin >> type;
        if (type == 1) {
            cin >> num2 >> num1;
            div2_rounds.push_back(num2);
            div1_rounds.push_back(num1);
        } else {
            cin >> num2;
            div2_rounds.push_back(num2);
        }
        rounds.push_back(num2);
    }

    sort(rounds.begin(), rounds.end());
    sort(div1_rounds.begin(), div1_rounds.end());
    sort(div2_rounds.begin(), div2_rounds.end());

    int min_missed = 0, max_missed = 0;
    for (int i = 1; i <= x-1; i++) {
        if (find(rounds.begin(), rounds.end(), i) == rounds.end()) {
            min_missed++;
        }
    }

    for (int i = 0; i < k; i++) {
        if (div1_rounds[i] < x && find(rounds.begin(), rounds.end(), div1_rounds[i]) == rounds.end()) {
            max_missed++;
        }
    }

    cout << min_missed << " " << max_missed << endl;

    return 0;
}