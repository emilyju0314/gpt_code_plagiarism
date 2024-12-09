#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    
    string shapes;
    cin >> shapes;
    
    vector<int> record(n, 0);
    
    for(int i = 0; i < n; i++) {
        char shape = shapes[i];
        if(shape == 'R') {
            record[i] = 0;
        } else if(shape == 'P') {
            record[i] = 1;
        } else {
            record[i] = 2;
        }
    }
    
    int mixedCount = n;
    vector<int> results;
    results.push_back(mixedCount);
    
    for(int i = 0; i < q; i++) {
        int player;
        char shape;
        cin >> player >> shape;
        player--;
        
        char currentShape = shapes[player];
        
        if((currentShape == 'R' && shape == 'S') ||
           (currentShape == 'P' && shape == 'R') ||
           (currentShape == 'S' && shape == 'P')) {
            record[player] = 0;
        } else if((currentShape == 'R' && shape == 'P') ||
                  (currentShape == 'P' && shape == 'S') ||
                  (currentShape == 'S' && shape == 'R')) {
            record[player] = 1;
        } else {
            record[player] = 2;
        }
        
        mixedCount = 0;
        for(int j = 0; j < n; j++) {
            if(record[j] == 2) {
                mixedCount++;
            }
        }
        
        results.push_back(mixedCount);
        shapes[player] = shape;
    }
    
    for(int result : results) {
        cout << result << endl;
    }
    
    return 0;
}