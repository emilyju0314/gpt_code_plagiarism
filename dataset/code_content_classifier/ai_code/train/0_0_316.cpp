#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> sequence(N);
    for(int i = 0; i < N; i++) {
        cin >> sequence[i];
    }

    int max_val = *max_element(sequence.begin(), sequence.end());
    for(int i = 0; i < N; i++) {
        if(sequence[i] == max_val) {
            cout << *max_element(sequence.begin() + (i+1) % N, sequence.end()) << endl;
        } else {
            cout << max_val << endl;
        }
    }

    return 0;
}