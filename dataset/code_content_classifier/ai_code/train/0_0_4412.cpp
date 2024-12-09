#include <iostream>
#include <vector>

using namespace std;

int calculateXN(int N, vector<pair<int, int>> operations) {
    int X = 0;
    for (int i = 0; i < N; i++) {
        int op = operations[i].first;
        int Y = operations[i].second;
        
        if (op == 1) {
            X += Y;
        } else if (op == 2) {
            X -= Y;
        } else if (op == 3) {
            X *= Y;
        } else if (op == 4) {
            X /= Y;
        }
    }
    return X;
}

int main() {
    int N;
    cin >> N;
    
    vector<pair<int, int>> operations(N);
    for (int i = 0; i < N; i++) {
        int op, Y;
        cin >> op >> Y;
        operations[i] = make_pair(op, Y);
    }
    
    int result = calculateXN(N, operations);
    cout << result << endl;
    
    return 0;
}