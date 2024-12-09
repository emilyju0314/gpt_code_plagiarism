#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<vector<char>> field;
vector<vector<vector<int>>> blackSquares;

bool isValidSquare(int x, int y, int size) {
    for (int i = x; i < x + size; i++) {
        for (int j = y; j < y + size; j++) {
            if (field[i][j] == '.') return false;
        }
    }
    return true;
}

bool isFractal(int x, int y, int size) {
    if (!isValidSquare(x, y, size)) return false;
    
    for (int i = 0; i < 4; i++) {
        bool found = false;
        for (int j = 0; j < blackSquares[x + i*size/2][y + i*size/2].size(); j++) {
            if (blackSquares[x + i*size/2][y + i*size/2][j] == size/2) {
                found = true;
                break;
            }
        }
        if (!found) return false;
    }
    
    return true;
}

int main() {
    cin >> n >> m;
    
    field.resize(n, vector<char>(m));
    blackSquares.resize(n, vector<vector<int>>(m));
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> field[i][j];
            if (field[i][j] == '*') {
                blackSquares[i][j].push_back(1);
            }
        }
    }
    
    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int size = 2; i+size <= n && j+size <= m; size *= 2) {
                if (isFractal(i, j, size)) count++;
            }
        }
    }
    
    cout << count << endl;
    
    return 0;
}