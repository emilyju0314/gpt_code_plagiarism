#include <iostream>
#include <vector>

using namespace std;

int countDivisions(long long n, vector<int> &boxes) {
    int divisions = 0;
    
    for (int i = 0; i < boxes.size(); i++) {
        int currBox = boxes[i];
        while (n < currBox && currBox > 0) {
            currBox /= 2;
            divisions++;
        }
        if (n == currBox) {
            return divisions;
        }
    }
    
    return -1;
}

int main() {
    int t;
    cin >> t;
    
    for (int i = 0; i < t; i++) {
        long long n;
        int m;
        cin >> n >> m;
        
        vector<int> boxes(m);
        for (int j = 0; j < m; j++) {
            cin >> boxes[j];
        }
        
        int result = countDivisions(n, boxes);
        cout << result << endl;
    }
    
    return 0;
}