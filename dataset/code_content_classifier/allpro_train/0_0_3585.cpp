#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> points(n);
    for (int i = 0; i < n; i++) {
        cin >> points[i];
    }
    
    sort(points.begin(), points.end());
    
    for (int i = 0; i < n-1; i++) {
        for (int j = i+1; j < n-1; j++) {
            if ((points[i] < points[j]) && (points[i+1] > points[j+1]) || (points[i] > points[j]) && (points[i+1] < points[j+1])) {
                cout << "yes" << endl;
                return 0;
            }
        }
    }
    
    cout << "no" << endl;
    
    return 0;
}