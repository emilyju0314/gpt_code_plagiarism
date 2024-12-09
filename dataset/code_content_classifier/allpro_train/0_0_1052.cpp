#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    // Formula to calculate number of cells in an n-th order rhombus: 2*n*n - 2*n + 1
    int cells = 2*n*n - 2*n + 1;
    
    cout << cells << endl;
    
    return 0;
}