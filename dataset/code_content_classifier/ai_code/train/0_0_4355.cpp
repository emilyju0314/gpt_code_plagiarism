#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> front(2 * n + 1), back(2 * n + 1);
    vector<int> balance(2 * n + 1, 0);

    for (int i = 1; i <= 2 * n; i++) {
        cin >> front[i] >> back[i];
        balance[front[i]]++;
        balance[back[i]]--;
    }

    vector<int> positive, negative;
    for (int i = 1; i <= 2 * n; i++) {
        if (balance[i] != 0) {
            cout << "NO" << endl;
            return 0;
        }
        if (front[i] > 0) positive.push_back(i);
        else negative.push_back(i);
    }

    cout << "YES" << endl;
    for (int i = 0; i < n; i++) {
        cout << positive[i] << " " << negative[i] << endl;
    }

    return 0;
}