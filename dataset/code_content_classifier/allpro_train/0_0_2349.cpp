#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> prices(n);
    vector<int> standards(n);
    vector<int> beauty(n);

    for (int i = 0; i < n; i++) {
        cin >> prices[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> standards[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> beauty[i];
    }

    vector<int> income(m);
    vector<int> preferred_beauty(m);

    for (int i = 0; i < m; i++) {
        cin >> income[i];
    }

    for (int i = 0; i < m; i++) {
        cin >> preferred_beauty[i];
    }

    for (int i = 0; i < m; i++) {
        int count = 0;
        for (int j = 0; j < n; j++) {
            if (prices[j] <= income[i] && income[i] <= standards[j] && abs(beauty[j] - preferred_beauty[i]) <= (income[i] - prices[j])) {
                count++;
            }
        }
        cout << count << " ";
    }

    return 0;
}