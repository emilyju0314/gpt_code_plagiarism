#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

struct Cake {
    int radius;
    int height;
};

bool compare(const Cake& c1, const Cake& c2) {
    return (double)c1.radius*c1.radius*c1.height > (double)c2.radius*c2.radius*c2.height;
}

int main() {
    int n;
    cin >> n;

    vector<Cake> cakes(n);
    for(int i = 0; i < n; i++) {
        cin >> cakes[i].radius >> cakes[i].height;
    }

    sort(cakes.begin(), cakes.end(), compare);

    vector<double> dp(n);
    for(int i = 0; i < n; i++) {
        dp[i] = M_PI*cakes[i].radius*cakes[i].radius*cakes[i].height;
        for(int j = 0; j < i; j++) {
            if(cakes[j].radius < cakes[i].radius && cakes[j].height < cakes[i].height) {
                dp[i] = max(dp[i], dp[j] + M_PI*cakes[i].radius*cakes[i].radius*cakes[i].height);
            }
        }
    }

    double maxVolume = 0;
    for(int i = 0; i < n; i++) {
        maxVolume = max(maxVolume, dp[i]);
    }

    cout << fixed << maxVolume << endl;

    return 0;
}