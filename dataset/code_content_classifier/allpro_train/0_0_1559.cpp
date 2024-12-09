#include <iostream>
#include <vector>

using namespace std;

long long calculate_sum_of_labor(vector<pair<int, int>>& books, int C) {
    int N = books.size();
    long long total_labor = 0;
    
    for (int i = 1; i < N; i++) {
        total_labor += min(books[i].second, books[i-1].second) + C * max(0, books[i-1].second + books[i].second - max(books[i-1].second, books[i].second));
    }
    
    return total_labor;
}

int main() {
    int N, C;
    cin >> N >> C;
    
    vector<pair<int, int>> books(N);
    
    for (int i = 0; i < N; i++) {
        cin >> books[i].first >> books[i].second;
    }
    
    long long min_labor = calculate_sum_of_labor(books, C);
    cout << min_labor << endl;
    
    return 0;
}