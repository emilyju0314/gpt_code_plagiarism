#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int N;
    double P;
    
    cin >> N >> P;
    
    double prob_not_select = 1.0;
    for(int i = 0; i < N-1; i++) {
        prob_not_select *= ((N-1) - i) / (double)(N - i);
        if (1.0 - prob_not_select >= P) {
            cout << i << endl;
            break;
        }
    }
    
    return 0;
}