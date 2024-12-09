#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int n, t;
    cin >> n >> t;

    long double result = n * (pow(1.000000011, t)); // Calculate the estimated number of transistors

    cout << fixed << setprecision(9) << result << endl; // Output the result with precision up to 9 decimal points

    return 0;
} 

// The code above reads two integers n and t as input and calculates the estimate of the number of transistors in a dense integrated circuit after t seconds based on Moore's law. The result is then outputted with a precision of 9 decimal points.