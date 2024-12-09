#include <iostream>
#include <vector>

using namespace std;

// Function to check which figure is placed on the plane
char checkFigure(vector<string>& plane) {
    char figure;
    
    if (plane[1][1] == '1' && plane[1][2] == '1' && plane[2][1] == '1') {
        figure = 'A';
    } else if (plane[2][0] == '1' && plane[2][1] == '1' && plane[2][2] == '1') {
        figure = 'B';
    } else if (plane[0][0] == '1' && plane[0][1] == '1' && plane[0][2] == '1' && plane[0][3] == '1') {
        figure = 'C';
    } else if (plane[1][1] == '1' && plane[2][0] == '1' && plane[2][1] == '1') {
        figure = 'D';
    } else if (plane[1][0] == '1' && plane[1][1] == '1' && plane[2][1] == '1') {
        figure = 'E';
    } else if (plane[0][0] == '1' && plane[1][0] == '1' && plane[1][1] == '1') {
        figure = 'F';
    } else {
        figure = 'G';
    }
    
    return figure;
}

int main() {
    while (true) {
        vector<string> plane(8);
        
        for (int i = 0; i < 8; i++) {
            cin >> plane[i];
        }
        
        char figure = checkFigure(plane);
        cout << figure << endl;
        
        string blankLine;
        getline(cin, blankLine); // Read the blank line to separate datasets
        if (blankLine.empty()) {
            break;
        }
    }
    
    return 0;
}