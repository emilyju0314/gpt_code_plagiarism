#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Point {
    int x, y;
};

bool comparePoints(Point p1, Point p2) {
    if (p1.x != p2.x) {
        return p1.x < p2.x;
    } else {
        return p1.y < p2.y;
    }
}

int main() {
    int N;
    cin >> N;
    
    while (N != 0) {
        vector<vector<int>> grid(N, vector<int>(N));
        
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                char c;
                cin >> c;
                grid[i][j] = c - '0';
            }
        }
        
        vector<Point> vertices;
        
        for (int i = 1; i < N-1; i++) {
            for (int j = 1; j < N-1; j++) {
                if (grid[i][j] == 4) {
                    vertices.push_back({j, N-i});
                }
            }
        }
        
        sort(vertices.begin(), vertices.end(), comparePoints);
        
        cout << vertices.size() << endl;
        for (int i = 0; i < vertices.size(); i++) {
            cout << vertices[i].x << " " << vertices[i].y << endl;
        }
        
        cin >> N;
    }
    
    return 0;
}