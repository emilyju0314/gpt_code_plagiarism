#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

struct Peak {
    int a;
    int p;
    int q;
};

double mountainBoundary(int W, int H, vector<Peak>& peaks) {
    double length = 0.0;
    
    for (double x = 0; x < W; x += 0.001) { // use a small increment for higher accuracy
        double max_height = 0.0;
        
        for (const Peak& peak : peaks) {
            double y = peak.a * pow(x - peak.p, 2) + peak.q;
            max_height = max(max_height, y);
        }
        
        length += max(H - max_height, 0.0);
    }
    
    return length;
}

int main() {
    int W, H, N;
    cin >> W >> H >> N;
    
    vector<Peak> peaks(N);
    for (int i = 0; i < N; i++) {
        cin >> peaks[i].a >> peaks[i].p >> peaks[i].q;
    }
    
    double length = mountainBoundary(W, H, peaks);
    cout << length << endl;
    
    return 0;
}