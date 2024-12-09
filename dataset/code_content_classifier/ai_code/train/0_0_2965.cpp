#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int w, b;
    cin >> w >> b;

    double prob = 0.0;
    
    if (b == 0) {
        prob = 1.0; // if there are no black mice, princess always wins
    } else if (w == 0) {
        prob = 0.0; // if there are no white mice, princess never wins
    } else {
        double pb = (double)b / (double)(w + b); // probability of drawing a black mouse
        double pw = (double)w / (double)(w + b); // probability of drawing a white mouse
        
        prob = pw; // princess draws white mouse on first turn
        
        for (int i = 1; i < w; i++) {
            prob += pw * (1 - pb) * (1 - pw) * (pb / (1.0 + pb - (i / 2.0)));
        }
    }

    cout << setprecision(9) << fixed << prob << endl;

    return 0;
}