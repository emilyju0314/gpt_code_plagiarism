#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main() {
    int id;
    string documentName, text;

    cin >> id;
    cin.ignore(); // to clear the newline character
    getline(cin, documentName);

    while (getline(cin, text)) {
        // process the text of the document here
    }

    // You can add your logic here to determine the subject based on the document content

    // For now, let's assume we return subject 1
    cout << 1 << endl;

    return 0;
} 

// Remember to test the program with sample inputs to ensure it works correctly.