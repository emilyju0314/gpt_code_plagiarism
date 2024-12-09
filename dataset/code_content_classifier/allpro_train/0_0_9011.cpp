#include <iostream>
#include <vector>

using namespace std;

// Function to generate the Thorse-Radewoosh sequence up to a certain length
vector<int> generateThorseRadewooshSequence(int d, int m, vector<int>& gen, int length) {
    vector<int> sequence = {0};
    for (int k = 1; sequence.size() < length; k++) {
        for (int i = 0; i < d; i++) {
            int shift = gen[i];
            vector<int> copy = sequence;
            for (int j = 0; j < copy.size(); j++) {
                copy[j] = (copy[j] + shift) % m;
            }
            sequence.insert(sequence.end(), copy.begin(), copy.end());
        }
    }
    return sequence;
}

int main() {
    int d, m;
    cin >> d >> m;
    
    vector<int> gen(d);
    for (int i = 0; i < d; i++) {
        cin >> gen[i];
    }
    
    int n;
    cin >> n;
    
    vector<int> B(n);
    for (int i = 0; i < n; i++) {
        cin >> B[i];
    }
    
    long long l, r;
    cin >> l >> r;
    
    vector<int> A = generateThorseRadewooshSequence(d, m, gen, r);
    
    int count = 0;
    for (int i = 0; i <= r - l - n; i++) {
        bool majorizes = true;
        for (int j = 0; j < n; j++) {
            if (B[j] < A[i + j + l - 1]) {
                majorizes = false;
                break;
            }
        }
        if (majorizes) {
            count++;
        }
    }
    
    cout << count << endl;

    return 0;
}