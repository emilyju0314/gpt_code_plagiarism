#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    int largest = 0;
    for (int i = 0; i < n; i++) {
        int ai;
        cin >> ai;
        if (ai > largest) {
            largest = ai;
        }
    }
    
    cout << largest << endl;
    
    return 0;
}