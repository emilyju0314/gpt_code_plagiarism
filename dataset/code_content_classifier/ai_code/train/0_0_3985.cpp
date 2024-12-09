#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int parent(int i) {
    return i / 2;
}

int left_child(int i) {
    return 2 * i;
}

int right_child(int i) {
    return 2 * i + 1;
}

int main() {
    int H;
    cin >> H;
    
    vector<int> heap(H+1);
    for (int i = 1; i <= H; i++) {
        cin >> heap[i];
    }
    
    for (int i = 1; i <= H; i++) {
        cout << "node " << i << ": key = " << heap[i] << ", ";
        
        if (parent(i) > 0) {
            cout << "parent key = " << heap[parent(i)] << ", ";
        }
        
        if (left_child(i) <= H) {
            cout << "left key = " << heap[left_child(i)] << ", ";
        }
        
        if (right_child(i) <= H) {
            cout << "right key = " << heap[right_child(i)] << ", ";
        }
        
        cout << endl;
    }
    
    return 0;
}