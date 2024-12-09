#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;
    
    vector<int> chairs(N, 0);
    for (int i = 0; i < N; i++) {
        int id;
        cin >> id;
        chairs[id - 1] = i + 1;
    }
    
    vector<int> result(N);
    for (int i = 0; i < N; i++) {
        int current_chair = chairs[i];
        result[current_chair - 1] = i + 1;
    }
    
    for (int i = 0; i < N; i++) {
        cout << result[i] << endl;
    }
    
    return 0;
}