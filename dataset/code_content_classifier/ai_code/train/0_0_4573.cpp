#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> arrivalTimes = {0, 5, 10, 15, 20, 25, 30, 35, 40, 45}; // Arrival times for the first 10 groups
    vector<int> numPeople = {2, 5, 2, 2, 2, 2, 5, 2, 2, 2}; // Number of people in each group
    vector<int> mealTimes = {19, 39, 25, 36, 22, 42, 19, 39, 25, 36}; // Meal times for each group
    
    int n;
    
    while (cin >> n) {
        int waitTime = 0;
        for (int i = 0; i < n; i++) {
            int groupArrival = arrivalTimes[i];
            int groupMealTime = mealTimes[i];
            int remainingSeats = 17;
            
            for (int j = 0; j < i; j++) {
                if (arrivalTimes[j] + mealTimes[j] <= groupArrival) { // Check if previous group has left by the time the current group arrives
                    remainingSeats += numPeople[j]; // Add the number of seats the previous group occupied
                }
            }
            
            if (numPeople[i] <= remainingSeats) {
                waitTime = 0;
            } else {
                int seatsNeeded = numPeople[i];
                for (int j = i - 1; j >= 0; j--) {
                    if (arrivalTimes[j] + mealTimes[j] <= groupArrival) {
                        break; // Stop checking as this is the earliest group that can leave before the current group arrives
                    }
                    seatsNeeded -= numPeople[j];
                }
                waitTime = (seatsNeeded * 5) - (17 * (i % 2) + 3 * (i % 3) + 19); // Calculate the wait time for the current group
            }
        }

        cout << waitTime << endl;
    }
    
    return 0;
}