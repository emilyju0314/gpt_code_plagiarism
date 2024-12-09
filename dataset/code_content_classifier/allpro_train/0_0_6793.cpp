#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<vector<char>> apartment;
vector<vector<char>> newApartment;

bool isValid(int i, int j) {
    return i >= 0 && i < n && j >= 0 && j < m;
}

void removeWalls(int i, int j) {
    if (!isValid(i, j) || apartment[i][j] == '.') return;
    
    apartment[i][j] = '.';
    
    removeWalls(i-1, j);
    removeWalls(i+1, j);
    removeWalls(i, j-1);
    removeWalls(i, j+1);
}

int main() {
    cin >> n >> m;
    
    apartment.resize(n, vector<char>(m));
    newApartment.resize(n, vector<char>(m));
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> apartment[i][j];
        }
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (apartment[i][j] == '*') {
                apartment[i][j] = '.';
                removeWalls(i, j);
            }
        }
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << apartment[i][j];
        }
        cout << endl;
    }
    
    return 0;
}