#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

bool isInsideCurve(int A, int B, int C, int D, int E, int F, int x, int y) {
    return A*x*x + B*x*y + C*y*y + D*x + E*y + F <= 0;
}

bool isOnLine(int Ai, int Bi, int Ci, int x, int y) {
    return Ai*x + Bi*y + Ci == 0;
}

int main() {
    int N;
    cin >> N;
    
    int A, B, C, D, E, F;
    cin >> A >> B >> C >> D >> E >> F;
    
    vector<int> Ais(N), Bis(N), Cis(N);
    for (int i = 0; i < N; i++) {
        cin >> Ais[i] >> Bis[i] >> Cis[i];
    }
    
    int count = 0;
    
    for (int i = -100; i <= 100; i++) {
        for (int j = -100; j <= 100; j++) {
            bool isInside = isInsideCurve(A, B, C, D, E, F, i, j);
            
            bool isInsideAllLines = true;
            for (int k = 0; k < N; k++) {
                if (!isOnLine(Ais[k], Bis[k], Cis[k], i, j)) {
                    isInsideAllLines = false;
                    break;
                }
            }
            
            if (isInside && isInsideAllLines) {
                count++;
            }
        }
    }
    
    cout << count << endl;
    
    return 0;
}