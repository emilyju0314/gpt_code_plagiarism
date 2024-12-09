#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(string a, string b) {
    for (int i = 0; i < a.length(); i++) {
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
    
    return false; // strings are equal
}

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<string> books(n);
    
    for (int i = 0; i < n; i++) {
        cin >> books[i];
    }
    
    // Sort the books according to the criteria
    sort(books.begin(), books.end(), compare);
    
    // Output the indices of the sorted books
    for (int i = 0; i < n; i++) {
        cout << i + 1 << " ";
    }
    
    return 0;
}