#include <iostream>
#include <vector>
#include <cmath>
#include <limits>

using namespace std;

double calculateQuantizationError(double originalValue, double quantizedValue) {
    return pow(originalValue - quantizedValue, 2);
}

double quantizeValue(double value, double Vmin, double Vmax, int quantizationLevel) {
    double quantizedValue;
    for (int i = 1; i <= 2*quantizationLevel; i++) {
        double quantizationStep = (Vmax - Vmin) / (2*quantizationLevel - 1);
        double candidateValue = Vmin + (i - 1)*quantizationStep;
        if (i == 1 || abs(value - quantizedValue) > abs(value - candidateValue)) {
            quantizedValue = candidateValue;
        }
    }
    return quantizedValue;
}

double adaptiveTimeSlicingQuantization(const vector<double>& values, int M, int L) {
    double minError = numeric_limits<double>::max();
    
    for (int start = 0; start <= values.size() - M; start++) {
        double Vmin = *min_element(values.begin() + start, values.begin() + start + M);
        double Vmax = *max_element(values.begin() + start, values.begin() + start + M);
        
        double error = 0;
        for (int i = start; i < start + M; i++) {
            double quantizedValue = quantizeValue(values[i], Vmin, Vmax, L);
            error += calculateQuantizationError(values[i], quantizedValue);
        }
        
        minError = min(minError, error);
    }
    
    return minError;
}

int main() {
    int N, M, L;
    
    while (true) {
        cin >> N >> M >> L;
        if (N == 0 && M == 0 && L == 0) {
            break;
        }
        
        vector<double> values(N);
        for (int i = 0; i < N; i++) {
            cin >> values[i];
        }
        
        double minError = adaptiveTimeSlicingQuantization(values, M, L);
        
        cout << fixed;
        cout.precision(2);
        cout << minError << endl;
    }
    
    return 0;
}