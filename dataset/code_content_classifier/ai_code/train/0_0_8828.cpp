#include <iostream>
#include <vector>

using namespace std;

bool isValidSequence(vector<int>& sequence, vector<vector<int>>& functions, int index) {
    if(index >= sequence.size()) {
        return true;
    }
    
    for(auto& func : functions) {
        if(func[0] == sequence[index]) {
            if(isValidSequence(sequence, functions, index + 1)) {
                return true;
            }
        }
        
        if(func[1] == sequence[index] && index + 1 < sequence.size()) {
            if(isValidSequence(sequence, functions, index + 2)) {
                return true;
            }
        }
    }
    
    return false;
}

int main() {
    int N, M;
    cin >> N;
    
    vector<int> sequence(N);
    
    for(int i = 0; i < N; i++) {
        cin >> sequence[i];
    }
    
    cin >> M;
    
    vector<vector<int>> functions(M, vector<int>(3));
    
    for(int i = 0; i < M; i++) {
        for(int j = 0; j < 3; j++) {
            cin >> functions[i][j];
        }
    }
    
    if(isValidSequence(sequence, functions, 0)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    
    return 0;
}