#include <iostream>
#include <vector>
#include <string>

using namespace std;

void paintFractal(vector<string>& canvas, int n, int k, int x, int y, int size) {
    if (size == 1) {
        return;
    }
    
    int new_size = size / n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (canvas[x + i][y + j] == '.') {
                paintFractal(canvas, n, k, x + i * new_size, y + j * new_size, new_size);
            } else {
                for (int p = 0; p < new_size; p++) {
                    for (int q = 0; q < new_size; q++) {
                        canvas[x + i * new_size + p][y + j * new_size + q] = '*';
                    }
                }
            }
        }
    }
}

int main() {
    int n, k;
    cin >> n >> k;
    
    vector<string> canvas(n);
    for (int i = 0; i < n; i++) {
        cin >> canvas[i];
    }
    
    for (int i = 0; i < k; i++) {
        paintFractal(canvas, n, k, 0, 0, n);
    }
    
    for (int i = 0; i < n * k; i++) {
        cout << canvas[i] << endl;
    }
    
    return 0;
}