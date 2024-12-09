#include <iostream>
#include <vector>

using namespace std;

bool canClearGame(vector<int>& sequence) {
    bool changed = true;
    while (changed) {
        changed = false;
        for (int i = 0; i < sequence.size(); i++) {
            int start = i;
            int end = i;
            while (end < sequence.size() && sequence[end] == sequence[i]) {
                end++;
            }
            if (end - start >= 2) {
                sequence.erase(sequence.begin() + start, sequence.begin() + end);
                changed = true;
                break;
            }
        }
    }
    return sequence.empty();
}

int main() {
    int N;
    cin >> N;
    vector<int> sequence(N);
    
    for (int i = 0; i < N; i++) {
        cin >> sequence[i];
    }
    
    if (canClearGame(sequence)) {
        cout << "yes" << endl;
    } else {
        cout << "no" << endl;
    }
    
    return 0;
}