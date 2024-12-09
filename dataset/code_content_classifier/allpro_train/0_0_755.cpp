#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;
    
    vector<int> heights(N);
    for (int i = 0; i < N; i++) {
        cin >> heights[i];
    }
    
    int count = 1;
    int max_height = heights[0];
    
    for (int i = 1; i < N; i++) {
        if (heights[i] >= max_height) {
            count++;
            max_height = max(max_height, heights[i]);
        }
    }
    
    cout << count << endl;
    
    return 0;
}