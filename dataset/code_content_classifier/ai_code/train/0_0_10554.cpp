#include <iostream>
using namespace std;

int main() {
    int scores[5];
    int sum = 0;
    
    // Input the final exam scores of the five students
    for (int i = 0; i < 5; i++) {
        cin >> scores[i];
        if (scores[i] < 40) {
            scores[i] = 40;
        }
        sum += scores[i];
    }
    
    // Calculate the average score
    float average = static_cast<float>(sum) / 5;
    
    // Output the average score
    cout << average << endl;
    
    return 0;
}