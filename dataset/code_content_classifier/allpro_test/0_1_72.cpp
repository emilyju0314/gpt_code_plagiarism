#include <iostream>
using namespace std;

int main() {
    int query;
    
    // First query
    cout << "? 2 2" << endl;
    cin >> query;
    if(query == -1) {
        return 1;
    }
    
    // Second query
    cout << "? 5 5" << endl;
    cin >> query;
    if(query == -1) {
        return 1;
    }
    
    // Third query
    cout << "? 4 7" << endl;
    cin >> query;
    if(query == -1) {
        return 1;
    }
    
    // Fourth query
    cout << "? 1 5" << endl;
    cin >> query;
    if(query == -1) {
        return 1;
    }
    
    // Output the answer
    cout << "! 2 3 4 5" << endl;
    
    return 0;
}