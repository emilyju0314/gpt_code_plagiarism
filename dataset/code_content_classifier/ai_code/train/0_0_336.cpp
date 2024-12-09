#include <iostream>
#include <string>

using namespace std;

int main() {
    int N;
    string S;
    
    // Input the number of questions and correctness string
    cin >> N >> S;
    
    int count = 0; // Initialize count of correct answers
    
    bool flag = false; // Flag to indicate if two consecutive wrong answers are found
    
    // Iterate through the correctness string
    for(int i = 0; i < N; i++) {
        if(S[i] == 'o') {
            count++; // Increment count if the answer is correct
        } else {
            if(flag) {
                break; // Break if two consecutive wrong answers are found
            }
            flag = true; // Set flag to true for the first wrong answer
        }
    }
    
    // Output the number of questions that AOR Ika-chan could write
    cout << count << endl;
    
    return 0;
}