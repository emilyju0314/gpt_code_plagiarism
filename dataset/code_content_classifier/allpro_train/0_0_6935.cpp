#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    string steps;
    cin >> steps;

    int num_correct_steps = 0;
    int num_total_steps = steps.length();

    for(int i = 0; i < steps.length(); i++) {
        if(i == 0)
            num_correct_steps += (steps[i] != steps[i+1]);
        else if(i == steps.length()-1)
            num_correct_steps += (steps[i] != steps[i-1]);
        else
            num_correct_steps += (steps[i] != steps[i+1] && steps[i] != steps[i-1]);
    }

    double max_percentage = (double)num_correct_steps / num_total_steps * 100;
    cout.precision(6);
    cout << fixed << max_percentage << endl;

    return 0;
}