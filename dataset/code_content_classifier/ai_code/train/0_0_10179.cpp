#include <iostream>
#include <vector>

using namespace std;

bool coprime(int x, int y) {
    while (y != 0) {
        int temp = y;
        y = x % y;
        x = temp;
    }
    return x == 1;
}

int main() {
    int n;
    cin >> n;
    
    vector<int> mushrooms(n);
    for (int i = 0; i < n; i++) {
        cin >> mushrooms[i];
    }
    
    int count = 0;
    
    for (int i = 0; i < n; i++) {
        bool burst = false;
        
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            
            int a = mushrooms[i], b = mushrooms[j];
            if (coprime(a, b) && coprime(a, a*b) && coprime(b, a*b)) {
                burst = true;
                break;
            }
        }
        
        if (!burst) {
            count++;
        }
    }
    
    cout << count << endl;
    
    return 0;
}