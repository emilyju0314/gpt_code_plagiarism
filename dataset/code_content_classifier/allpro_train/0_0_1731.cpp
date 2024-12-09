#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    string S;
    
    // Input the phone number length and the phone number
    cin >> N;
    cin >> S;
    
    // Count the occurrences of each digit in the phone number
    vector<int> count(10, 0);
    for (int i = 0; i < N; i++) {
        count[S[i] - '0']++;
    }
    
    // Find the index of the smallest digit that occurs in the phone number
    int min_idx = 1;
    while (min_idx <= 9 && count[min_idx] == 0) {
        min_idx++;
    }
    
    // Rearrange the numbers based on the optimal placement
    vector<int> rearranged;
    for (int i = min_idx; i <= 9; i++) {
        for (int j = 0; j < count[i]; j++) {
            rearranged.push_back(i);
        }
    }
    
    // Output the rearranged numbers in the 3x3 grid
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << rearranged[i*3 + j];
        }
        cout << endl;
    }
    
    return 0;
}