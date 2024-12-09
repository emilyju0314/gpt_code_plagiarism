#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

double calculateWinningProbability(int N, int T, string colors) {
    int redCount = 0;
    for(char color : colors) {
        if(color == 'R') {
            redCount++;
        }
    }
    
    double totalCells = N;
    double redCells = redCount;
    
    if(redCount == 0) {
        return 0.0;
    } else if(redCount == N) {
        return 1.0;
    }
    
    double p = redCells / totalCells;
    double q = 1 - p;
    double ans = 0.0;
    
    if(p == q) {
        ans = 1.0 / (1 + (1 / (1 - p)));
    } else {
        ans = (1 - pow(q / p, T)) / (1 - pow(q / p, N));
    }
    
    return ans;
}

int main() {
    int N, T;
    
    while(true) {
        cin >> N >> T;
        
        if(N == 0 && T == 0) {
            break;
        }
        
        string colors;
        cin >> colors;
        
        double probability = calculateWinningProbability(N, T, colors);
        
        cout << fixed << setprecision(8) << probability << endl;
    }
    
    return 0;
}