#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int gcd(int a, int b) {
    if(b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int main() {
    int n;
    cin >> n;
    
    vector<vector<int>> points(n, vector<int>(3));
    for(int i = 0; i < n; i++) {
        cin >> points[i][0] >> points[i][1] >> points[i][2];
    }
    
    int max_gcd = 1;
    for(int i = 0; i < n; i++) {
        int g = gcd(points[i][0], gcd(points[i][1], points[i][2]));
        max_gcd = max(max_gcd, g);
    }
    
    cout << max_gcd * max_gcd << endl;
    
    // Find integer vectors r1, r2, r3
    int r = max_gcd;
    vector<int> r1 = {r, 0, 0};
    vector<int> r2 = {0, r, 0};
    vector<int> r3 = {0, 0, r};
    
    // Output r1, r2, r3
    cout << r1[0] << " " << r1[1] << " " << r1[2] << endl;
    cout << r2[0] << " " << r2[1] << " " << r2[2] << endl;
    cout << r3[0] << " " << r3[1] << " " << r3[2] << endl;
    
    return 0;
}