#include <iostream>
#include <deque>
#include <iomanip>

using namespace std;

int main() {
    int n;
    cin >> n;

    deque<int> indices;
    for (int i = 0; i < n; i++) {
        int volume;
        cin >> volume;
        
        if (indices.empty() || volume <= indices.back()) {
            indices.push_back(volume);
        } else {
            while (!indices.empty() && volume > indices.back()) {
                indices.pop_back();
            }
            indices.push_back(volume);
        }
    }

    double sum = 0.0;
    for (int i = 0; i < indices.size(); i++) {
        sum += indices[i];
    }
    double avg = sum / indices.size();

    for (int i = 0; i < n; i++) {
        cout << fixed << setprecision(9) << avg << endl;
    }

    return 0;
}