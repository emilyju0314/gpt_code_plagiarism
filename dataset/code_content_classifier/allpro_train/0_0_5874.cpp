#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;
    
    vector<int> bulbs(N);
    for (int i = 0; i < N; i++) {
        cin >> bulbs[i];
    }
    
    int max_length = 1;
    int current_length = 1;
    int prev_length = 1;
    
    for (int i = 1; i < N; i++) {
        if (bulbs[i] != bulbs[i-1]) {
            current_length++;
        } else {
            prev_length = current_length;
            current_length = 1;
        }
        max_length = max(max_length, min(current_length+1, prev_length+1));
    }
    
    cout << max_length << endl;
    
    return 0;
}