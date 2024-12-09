#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> a(m);
    for (int i = 0; i < m; i++) {
        cin >> a[i];
    }

    // Calculate the number of pages needed to turn without merging
    int total_pages = 0;
    for (int i = 1; i < m; i++) {
        total_pages += abs(a[i] - a[i-1]);
    }

    // Calculate the minimum number of pages to turn by potentially merging two pages
    int min_pages = total_pages;
    for (int i = 1; i < m-1; i++) {
        if (a[i-1] <= a[i+1]) {
            min_pages = min(min_pages, total_pages - abs(a[i] - a[i-1]) - abs(a[i+1] - a[i]) + abs(a[i+1] - a[i-1]));
        }
    }

    cout << min_pages << endl;

    return 0;
}