#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int n;
    string commands;
    
    cin >> n;
    cin >> commands;
    
    int total_positions = 1;
    
    for(int i = 0; i < n; i++) {
        if(commands[i] == 'L') {
            total_positions++;
        } else {
            total_positions--;
        }
    }
    
    total_positions++; // Add one more position for the initial position
    
    cout << total_positions << endl;
    
    return 0;
}