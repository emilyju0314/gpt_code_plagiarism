#include <iostream>
#include <cmath>

using namespace std;

const double EPS = 1e-10;

int main()
{
    int n;
    cin >> n;

    int hist[6];
    fill(hist, hist+6, 0);
    double h;
    while(n--) {
        cin >> h;
        if(h < 165.0) {
            hist[0]++;
        } else if(h + EPS > 165.0 && h < 170.0) {
            hist[1]++;
        } else if(h + EPS > 170.0 && h < 175.0) {
            hist[2]++;
        } else if(h + EPS > 175.0 && h < 180.0) {
            hist[3]++;
        } else if(h + EPS > 180.0 && h < 185.0) {
            hist[4]++;
        } else {
            hist[5]++;
        }
    }
    
    for(int i = 0; i < 6; i++) {
        cout << (i+1) << ":";
        for(int j = 0; j < hist[i]; j++) cout << "*";
        cout << endl;
    }
}