#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> sequence(n);
    for(int i=0; i<n; i++) {
        cin >> sequence[i];
    }

    string steps;
    cin >> steps;

    for(char c : steps) {
        vector<int> new_sequence;
        if(c == 'M') {
            for(int i=0; i<sequence.size()-1; i++) {
                new_sequence.push_back(max(sequence[i], sequence[i+1]));
            }
        } else if(c == 'm') {
            for(int i=0; i<sequence.size()-1; i++) {
                new_sequence.push_back(min(sequence[i], sequence[i+1]));
            }
        }
        sequence = new_sequence;
    }

    cout << sequence[0] << endl;

    return 0;
}