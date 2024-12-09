#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int N;
    double P;
    
    cin >> N >> P;
    
    int mapsToStudy = 0;
    double probability = 0;
    
    while(probability < P) {
        probability = 1 - (double)(N-mapsToStudy)/N;
        mapsToStudy++;
    }
    
    cout << mapsToStudy << endl;
    
    return 0;
}