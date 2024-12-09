#include <iostream>
#include <vector>

using namespace std;

int main() {
    int m, x, y;
    cin >> m;
    
    vector<int> c(m);
    for (int i = 0; i < m; i++) {
        cin >> c[i];
    }
    
    cin >> x >> y;
    
    int totalStudents = 0;
    for (int i = 0; i < m; i++) {
        totalStudents += c[i];
    }
    
    int passingRate = 0;
    for (int k = 1; k <= m; k++) {
        int begGroup = 0;
        int intGroup = 0;
        
        for (int i = 0; i < k; i++) {
            begGroup += c[i];
        }
        for (int i = k; i < m; i++) {
            intGroup += c[i];
        }
        
        if (begGroup >= x && begGroup <= y && intGroup >= x && intGroup <= y) {
            passingRate = k;
            break;
        }
    }
    
    cout << passingRate << endl;
    
    return 0;
}