#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int N;
    double P;
    
    cin >> N >> P;
    
    double prob = 0;
    int num_maps = 0;
    
    while(prob < P) {
        num_maps++;
        prob = 1 - (1.0 * (N - num_maps) / N);
    }
    
    cout << num_maps << endl;
    
    return 0;
}