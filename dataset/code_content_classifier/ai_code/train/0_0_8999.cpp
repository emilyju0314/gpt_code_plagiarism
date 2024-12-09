#include<iostream>
#include<string>
using namespace std;

// Function to check if a given position matches the input sequence
bool matchSequence(string sequence, string number, int pos) {
    for (int i = 0; i < sequence.length(); i++) {
        if (sequence[i] != number[pos + i]) {
            return false;
        }
    }
    return true;
}

// Function to find the position of the input sequence in Champernowne constant
long long findPosition(string sequence) {
    string number = "0";
    for (int i = 1; number.length() <= 100; i++) {
        number += to_string(i);
    }
    
    for (int i = 1; i < number.length(); i++) {
        if (matchSequence(sequence, number, i)) {
            return i + 1;
        }
    }
    return -1;
}

int main() {
    string input;
    
    while (true) {
        cin >> input;
        if (input == "#") {
            break;
        }
        
        long long position = findPosition(input);
        cout << position << endl;
    }
    
    return 0;
}