#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    long long n, m, k;
    cin >> n >> m >> k;

    vector<long long> specialItems(m);
    for (int i = 0; i < m; i++) {
        cin >> specialItems[i];
    }

    long long ops = 0, currentPage = 0;
    for (int i = 0; i < m; ) {
        long long currentPageStart = currentPage * k + 1;
        long long currentPageEnd = min(currentPageStart + k - 1, n);
        long long discarded = 0;

        while (i < m && specialItems[i] >= currentPageStart && specialItems[i] <= currentPageEnd) {
            i++;
            discarded++;
        }

        if (discarded > 0) {
            ops++;
        } else {
            long long nextPage = (specialItems[i] - 1) / k;
            currentPage = nextPage;
        }
    }

    cout << ops << endl;

    return 0;
}