#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int main() {
    int n;
    while (cin >> n && n != 0) {
        vector<pair<int, double>> closest_persons;
        double ideal_bmi = 22;
        
        int reception_number;
        double height, weight;
        double min_diff = INT_MAX;
        
        for (int i = 0; i < n; i++) {
            cin >> reception_number >> height >> weight;
            double bmi = weight / pow(height / 100, 2);
            double diff = abs(bmi - ideal_bmi);
            
            if (diff < min_diff) {
                closest_persons.clear();
                closest_persons.push_back({reception_number, diff});
                min_diff = diff;
            } else if (diff == min_diff) {
                closest_persons.push_back({reception_number, diff});
            }
        }
        
        int closest_reception_number;
        double min_reception_number = INT_MAX;
        
        for (auto person : closest_persons) {
            if (person.first < min_reception_number) {
                min_reception_number = person.first;
                closest_reception_number = person.first;
            }
        }
        
        cout << closest_reception_number << endl;
    }
    
    return 0;
}