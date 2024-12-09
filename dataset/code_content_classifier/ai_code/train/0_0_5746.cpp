#include <iostream>
#include <string>

using namespace std;

int main() {
    // Read input
    int n;
    cin >> n;
    string moves;
    cin >> moves;
    
    // Initialize variables
    int glasses = 0;
    
    // Check every possible starting point
    for(int start = 0; start < n; start++) {
        // Initialize variables for current starting point
        int current_glasses = 0;
        bool valid = true;
        
        // Check if Vasya could have drunk a glass of juice
        for(int i = 0; i < moves.size(); i++) {
            // Calculate the index of the person being pointed at
            int next = (start + i) % n;
            int next_next = (start + i + 1) % n;
            int next_next_next = (start + i + 2) % n;
            
            // Check for conditions to drink juice
            if(moves[next] == 'a' && moves[next_next] == 'b' && moves[next_next_next] == 'b') {
                current_glasses++;
            } else if(moves[next] == 'b' && moves[next_next] == 'a' && moves[next_next_next] == 'b') {
                current_glasses++;
            } else if(moves[next] == 'b' && moves[next_next] == 'b' && moves[next_next_next] == 'a') {
                current_glasses++;
            } else {
                valid = false;
                break;
            }
        }
        
        // Update the maximum number of glasses of juice
        if(valid) {
            glasses = max(glasses, current_glasses);
        }
    }
    
    // Output the result
    cout << glasses << endl;

    return 0;
}