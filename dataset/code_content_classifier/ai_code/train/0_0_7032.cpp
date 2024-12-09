#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> cards(3*n);
    for (int i = 0; i < 3*n; i++) {
        cin >> cards[i];
    }
    
    vector<vector<int>> output(2*n, vector<int>(3));
    
    for (int i = 0; i < n; i++) {
        output[i*2][0] = cards[i];
        output[i*2][1] = cards[n+i];
        output[i*2][2] = cards[2*n+i];
        
        output[i*2+1][0] = output[i*2][0] + 1;
        output[i*2+1][1] = output[i*2][1] + 1;
        output[i*2+1][2] = output[i*2][2] + 1;
    }
    
    for (int i = 0; i < 2*n; i++) {
        cout << output[i][0] << " " << output[i][1] << " " << output[i][2] << endl;
    }
    
    return 0;
}