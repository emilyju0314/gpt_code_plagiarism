#include <iostream>
#include <vector>

using namespace std;

int main() {
    int V;
    cin >> V;

    for(int i = 0; i < V; i++) {
        vector<int> data(250);
        for(int j = 0; j < 250; j++) {
            cin >> data[j];
        }

        int sum = 0;
        for(int j = 0; j < 250; j++) {
            sum += data[j];
        }

        double mean = sum / 250.0;

        double poisson_sum = 0;
        for(int j = 0; j < 250; j++) {
            poisson_sum += (data[j] - mean) * (data[j] - mean);
        }

        double poisson_var = poisson_sum / 250.0;

        if(poisson_var < mean) {
            cout << "poisson" << endl;
        } else {
            cout << "uniform" << endl;
        }
    }

    return 0;
}