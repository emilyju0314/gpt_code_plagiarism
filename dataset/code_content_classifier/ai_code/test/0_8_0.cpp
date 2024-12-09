#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(const string& a, const string& b) {
    for(int i = 0; i < a.length(); i++) {
        if(i % 2 == 0) {
            if(a[i] != b[i]) {
                return a[i] < b[i];
            }
        } else {
            if(a[i] != b[i]) {
                return a[i] > b[i];
            }
        }
    }
    return false;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<pair<string, int>> books;
    for(int i = 0; i < n; i++) {
        string title;
        cin >> title;
        books.push_back({title, i+1});
    }

    sort(books.begin(), books.end(), [](const pair<string, int>& a, const pair<string, int>& b){
        return compare(a.first, b.first);
    });

    for(auto &book : books) {
        cout << book.second << " ";
    }

    return 0;
}