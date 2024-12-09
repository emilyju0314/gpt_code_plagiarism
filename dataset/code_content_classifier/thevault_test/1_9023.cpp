double FIR::filter(double input){
    // initialising an output variable and a counting variable for the coefficients array
    double output = 0;
    int n = 0;
    // writting the input value at the current position in the ring buffer
    buffer[current] = input;
    // calculating the filter response using a ring buffer
    while(current >= 0){
        output += buffer[current] * coeff[n];
        current--;
        n++;
    }
    current = num_taps-1;
    while(n < num_taps){
        output += buffer[current] * coeff[n];
        current--;
        n++;
    }
    
    // Incrementing the current position; setting to position 0 if the
    // number of taps is reached
    current++;
    if(current >= num_taps)
        current = 0;
    
    return output;
}