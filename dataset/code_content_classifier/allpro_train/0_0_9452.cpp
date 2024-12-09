#include <iostream>
#include <string>

using namespace std;

int main() {
    int l;
    string n;
    
    cin >> l;
    cin >> n;
    
    // Split the string into two parts
    string part1 = n.substr(0, l-1);
    string part2 = n.substr(l-1);
    
    // Convert the two parts into integers
    int num1 = stoi(part1);
    int num2 = stoi(part2);
    
    // Find the minimum sum of the two integers
    int sum = num1 + num2;
    
    cout << sum << endl;
    
    return 0;
}