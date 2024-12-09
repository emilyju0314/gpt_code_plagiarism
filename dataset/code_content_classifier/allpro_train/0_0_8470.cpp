#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int main() {
    long long N;
    cin >> N;
    
    // Find the length of the string by iterating through powers of 2
    int len = 1;
    while (pow(2, len) <= N) {
        len++;
    }
    
    // Generate the string that satisfies the conditions
    int num = 1;
    vector<int> s;
    for (int i = 0; i < len; i++) {
        s.push_back(num);
        s.push_back(num);
        num++;
    }
    
    // Output the results
    cout << len * 2 << endl;
    for (int i = 0; i < s.size(); i++) {
        cout << s[i] << " ";
    }
    
    return 0;
}