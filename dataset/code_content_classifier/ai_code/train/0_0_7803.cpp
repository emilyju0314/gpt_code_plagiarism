#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> castleX, castleY;
    for (int i = 0; i < n; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        castleX.push_back(a);
        castleX.push_back(c);
        castleY.push_back(b);
        castleY.push_back(d);
    }
    
    sort(castleX.begin(), castleX.end());
    sort(castleY.begin(), castleY.end());
    
    int minX = castleX[0];
    int minY = castleY[0];
    int maxX = castleX[2*n-1];
    int maxY = castleY[2*n-1];
    
    bool possible = true;
    for (int i = 0; i < n; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        if (a != minX || b != minY || c != maxX || d != maxY) {
            possible = false;
            break;
        }
    }
    
    if (possible) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    
    return 0;
}