#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m, q;
    cin >> n >> m >> q;
    
    vector<vector<int>> bookcase(n, vector<int>(m, 0));
    vector<vector<pair<int, int>>> operations(q);
    vector<int> booksCount(q+1, 0);
    
    for(int i = 0; i < q; i++) {
        int type;
        cin >> type;
        
        if(type == 1) {
            int shelf, position;
            cin >> shelf >> position;
            shelf--; position--;
            if(bookcase[shelf][position] == 0) {
                bookcase[shelf][position] = 1;
                booksCount[i+1] = booksCount[i] + 1;
            } else {
                booksCount[i+1] = booksCount[i];
            }
        } else if(type == 2) {
            int shelf, position;
            cin >> shelf >> position;
            shelf--; position--;
            if(bookcase[shelf][position] == 1) {
                bookcase[shelf][position] = 0;
                booksCount[i+1] = booksCount[i] - 1;
            } else {
                booksCount[i+1] = booksCount[i];
            }
        } else if(type == 3) {
            int shelf;
            cin >> shelf;
            shelf--;
            int count = count(bookcase[shelf].begin(), bookcase[shelf].end(), 1);
            for(int j = 0; j < m; j++) {
                if(bookcase[shelf][j] == 1) {
                    bookcase[shelf][j] = 0;
                } else {
                    bookcase[shelf][j] = 1;
                }
            }
            booksCount[i+1] = booksCount[i] + (m - 2 * count);
        } else if(type == 4) {
            int k;
            cin >> k;
            k--;
            operations[i] = operations[k];
            cout << booksCount[operations[i].size()] << endl;
        }
    }
    
    return 0;
}