#include <iostream>
#include <vector>

using namespace std;

void printCombination(int bitmask, int n) {
    vector<int> elements;
    
    for (int i = 0; i < n; i++) {
        if ((bitmask >> i) & 1) {
            elements.push_back(i);
        }
    }
    
    if (elements.size() == 0) {
        return;
    }

    cout << bitmask << ": ";
    for (int i = 0; i < elements.size(); i++) {
        cout << elements[i] << " ";
    }
    cout << endl;
}

void generateCombinations(int n, int k) {
    for (int bitmask = (1 << k) - 1; bitmask < (1 << n);) {
        printCombination(bitmask, n);
        
        int x = bitmask & -bitmask;
        int y = bitmask + x;
        bitmask = ((bitmask & ~y) / x >> 1) | y;
    }
}

int main() {
    int n, k;
    cin >> n >> k;
    
    generateCombinations(n, k);
    
    return 0;
}