#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<pair<int, pair<int, int>>> books(n);

    for (int i = 0; i < n; i++) {
        int t, a, b;
        cin >> t >> a >> b;
        books[i] = {t, {a, b}};
    }

    vector<int> alice_books, bob_books;
    
    for (int i = 0; i < n; i++) {
        if (books[i].second.first) alice_books.push_back(i + 1);
        if (books[i].second.second) bob_books.push_back(i + 1);
    }
    
    sort(alice_books.begin(), alice_books.end(), [&](int i, int j) {
        return books[i-1].first < books[j-1].first;
    });
    
    sort(bob_books.begin(), bob_books.end(), [&](int i, int j) {
        return books[i-1].first < books[j-1].first;
    });

    int min_sum = -1;
    
    for (int i = k; i <= m; i++) {
        if (alice_books.size() < i || bob_books.size() < i) continue;
        
        int sum = 0;
        for (int j = 0; j < i; j++) {
            sum += books[alice_books[j] - 1].first;
            sum += books[bob_books[j] - 1].first;
        }
        
        if (min_sum == -1 || sum < min_sum) {
            min_sum = sum;
        }
    }

    if (min_sum == -1) {
        cout << "-1" << endl;
    } else {
        cout << min_sum << endl;
        for (int i = 0; i < m; i++) {
            cout << alice_books[i] << " ";
        }
        cout << endl;
    }

    return 0;
}