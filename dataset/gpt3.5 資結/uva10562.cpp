#include <iostream>
#include <vector>
#include <string>

using namespace std;

void print_tree(const vector<string>& input, int row, int col) {
    // Base case: if row exceeds the input size, return
    if (row >= input.size()) {
        return;
    }

    // Print the current character
    char ch = input[row][col];
    cout << ch;

    // Check if it is a non-terminal character
    if (ch == '-' || ch == '|' || ch == '+') {
        // Find the start index of the next row
        int next_row = row + 1;
        while (next_row < input.size() && input[next_row].size() > col && input[next_row][col] == '|') {
            next_row++;
        }

        // Print the branches recursively
        for (int i = col + 1; i < input[row].size(); i++) {
            if (input[next_row][i] == '-') {
                print_tree(input, next_row, i);
            }
        }
    }
}

int main() {
    int t;
    cin >> t;
    string line;
    getline(cin, line); // Read the newline character

    while (t--) {
        vector<string> input;

        // Read the input tree
        while (getline(cin, line) && line[0] != '#') {
            input.push_back(line);
        }

        // Print the tree recursively
        for (int i = 0; i < input[0].size(); i++) {
            if (input[0][i] == '|') {
                print_tree(input, 0, i);
            }
        }
        cout << endl;
    }

    return 0;
}