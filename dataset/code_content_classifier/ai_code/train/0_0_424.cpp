#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;
    
    vector<pair<int, int>> squares(N);
    for (int i = 1; i < N; i++) {
        int n, d;
        cin >> n >> d;
        squares[i] = {n, d};
    }
    
    int minX = 0, minY = 0, maxX = 0, maxY = 0;
    
    for (int i = 1; i < N; i++) {
        int x = squares[i].first;
        int y = squares[i].second;
        
        if (x < minX) minX = x;
        if (y < minY) minY = y;
        if (x > maxX) maxX = x;
        if (y > maxY) maxY = y;
    }
    
    int area = (maxX - minX + 1) * (maxY - minY + 1);
    
    cout << area << endl;
    
    return 0;
}