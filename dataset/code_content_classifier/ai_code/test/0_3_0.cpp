#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(string a, string b) {
    for (int i = 0; i < a.size(); i++) {
        if (i % 2 == 0) { // even index, compare descending
            if (a[i] != b[i]) {
                return a[i] > b[i];
            }
        } else { // odd index, compare ascending
            if (a[i] != b[i]) {
                return a[i] < b[i];
            }
        }
    }
    return false;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<pair<string, int>> books;

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        books.push_back({s, i + 1});
    }

    sort(books.begin(), books.end(), compare);

    for (auto book : books) {
        cout << book.second << " ";
    }

    return 0;
}