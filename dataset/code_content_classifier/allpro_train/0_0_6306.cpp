#include <iostream>

using namespace std;

int main() {
    int A, B, X;
    cin >> A >> B >> X;

    int price = 0;
    
    // Calculate the total price for 1-liter bottles
    int num_1_liters = X / 1000;
    price += num_1_liters * A;

    // Calculate the total price for 0.5-liter bottles
    int num_half_liters = (X % 1000) / 500;
    price += num_half_liters * B;

    // Check if buying more 0.5-liter bottles is cheaper
    if (num_half_liters * B < (num_1_liters + 1) * A) {
        price = num_half_liters * B;
    }

    cout << price << endl;

    return 0;
}