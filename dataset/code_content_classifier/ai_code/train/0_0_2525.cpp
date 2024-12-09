#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int candies(vector<int>& sequence) {
    int count = 0;
    while (sequence.size() > 1) {
        vector<int> next_sequence;
        for (int i = 0; i < sequence.size(); i += 2) {
            int sum = sequence[i] + sequence[i + 1];
            if (sum >= 10) {
                count++;
            }
            next_sequence.push_back(sum % 10);
        }
        sequence = next_sequence;
    }
    return count;
}

int main() {
    int n;
    cin >> n;
    
    vector<int> sequence(n);
    for (int i = 0; i < n; i++) {
        cin >> sequence[i];
    }
    
    int q;
    cin >> q;
    
    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        
        vector<int> sub_sequence(sequence.begin() + l - 1, sequence.begin() + r);
        cout << candies(sub_sequence) << endl;
    }
    
    return 0;
}