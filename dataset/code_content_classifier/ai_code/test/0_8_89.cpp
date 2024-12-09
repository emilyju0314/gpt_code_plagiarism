#include <iostream>
#include <vector>

using namespace std;

bool isPossibleToEraseSequence(vector<int>& sequence) {
    int n = sequence.size();
    int largestElement = *max_element(sequence.begin(), sequence.end());
    
    // Count frequency of each element in the sequence
    vector<int> freq(largestElement + 1, 0);
    for(int i=0; i<n; i++) {
        freq[sequence[i]]++;
    }
    
    // Traverse the frequency array from largestElement to 1
    // If a number is present in freq array, it means it's not divisible by any index greater than its value
    // We need to check if all numbers in freq array have a frequency that is divisible by the number itself
    for(int i=largestElement; i>0; i--) {
        int count = freq[i];
        for(int j=i*2; j<=largestElement; j+=i) {
            count += freq[j];
        }
        if(count % i != 0) {
            return false; // If count is not divisible by i, then it's not possible to erase the whole sequence
        }
    }
    
    return true; // If we reach here, it's possible to erase the whole sequence
}

int main() {
    int t;
    cin >> t;
    
    while(t--) {
        int n;
        cin >> n;
        
        vector<int> sequence(n);
        
        for(int i=0; i<n; i++) {
            cin >> sequence[i];
        }
        
        if(isPossibleToEraseSequence(sequence)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    
    return 0;
}