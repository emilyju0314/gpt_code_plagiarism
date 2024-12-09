#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void printVector(vector<int> v) {
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}

void generateArrangements(int n, vector<int> arrangement) {
    if (n == 0) {
        printVector(arrangement);
        return;
    }
    for (int i = 1; i <= n; i++) {
        if (arrangement.empty() || i <= arrangement.back()) {
            arrangement.push_back(i);
            generateArrangements(n - i, arrangement);
            arrangement.pop_back();
        }
    }
}

int main() {
    int n;
    while (true) {
        cin >> n;
        if (n == 0) {
            break;
        }
        
        cout << n << endl;
        
        vector<int> arrangement;
        generateArrangements(n, arrangement);
    }
    
    return 0;
}