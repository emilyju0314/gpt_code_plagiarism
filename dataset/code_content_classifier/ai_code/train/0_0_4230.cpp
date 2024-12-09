#include <iostream>
#include <cmath>
#include <string>
#include <sstream>

using namespace std;

int main() {
    string input;
    
    while (getline(cin, input)) {
        stringstream ss(input);
        
        double x1, y1, x2, y2, xq, yq;
        char comma;
        
        ss >> x1 >> comma >> y1 >> comma >> x2 >> comma >> y2 >> comma >> xq >> comma >> yq;
        
        double midX = (x1 + x2) / 2.0;
        double midY = (y1 + y2) / 2.0;
        
        double dx = midX - xq;
        double dy = midY - yq;
        
        double newX = midX + dx;
        double newY = midY + dy;
        
        cout << fixed;
        cout.precision(6);
        cout << newX << " " << newY << endl;
    }

    return 0;
}