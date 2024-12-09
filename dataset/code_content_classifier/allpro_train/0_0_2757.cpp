#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;
    
    vector<int> distances(N);
    for(int i = 0; i < N; i++) {
        cin >> distances[i];
    }
    
    // Check if it's possible to complete the roundtrip
    bool possible = true;
    for(int i = 0; i < N-1; i++) {
        if(distances[i] < distances[i+1]) {
            possible = false;
            break;
        }
    }
    if(possible) {
        cout << "yes" << endl;
    } else {
        cout << "no" << endl;
    }
    
    return 0;
}