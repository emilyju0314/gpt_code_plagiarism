#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> books(n);
    for (int i = 0; i < n; i++) {
        cin >> books[i].first >> books[i].second;
    }

    sort(books.begin(), books.end());

    int total_thickness = 0;
    int total_width = 0;
    for (int i = 0; i < n; i++) {
        if (books[i].first == 1) {
            if (total_width <= total_thickness) {
                total_thickness++;
            } else {
                total_width += books[i].second;
            }
        } else {
            total_thickness += 2;
            total_width += books[i].second;
        }
    }

    cout << total_thickness << endl;

    return 0;
}