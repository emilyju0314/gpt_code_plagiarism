#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    long long n, m, k;
    cin >> n >> m >> k;

    vector<long long> special_items(m);
    for (int i = 0; i < m; i++) {
        cin >> special_items[i];
    }

    long long operations = 0;
    long long currentPage = 1;
    long long itemsLeft = m;

    for (int i = 0; i < m; ) {
        long long itemsOnPage = 0;
        while (i < m && special_items[i] <= currentPage * k) {
            i++;
            itemsOnPage++;
            itemsLeft--;
        }
        operations++;
        currentPage += itemsOnPage;
    }

    cout << operations << endl;

    return 0;
}