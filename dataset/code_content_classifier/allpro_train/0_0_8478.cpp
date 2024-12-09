#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<pair<int, int>> books;
    for (int i = 0; i < n; i++) {
        int price, rating;
        cin >> price >> rating;
        books.push_back(make_pair(rating, price));
    }
    
    sort(books.begin(), books.end());
    
    vector<int> ratings_count(m+1, 0);
    for (int i = 0; i < n; i++) {
        ratings_count[books[i].second]++;
    }
    
    int current_sum = 0;
    for (int i = 1; i <= m; i++) {
        current_sum += ratings_count[i];
        cout << current_sum << " ";
    }
    
    return 0;
}