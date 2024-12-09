#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int current_child = 1;
    for(int i = 1; i < n; i++) {
        // Calculate the next child to receive the ball
        int next_child = (current_child + i) % n;
        if(next_child == 0) {
            next_child = n;
        }
        
        cout << next_child << " ";
        current_child = next_child;
    }

    return 0;
}